#include <Bounce2.h>
/* send value when analog value changes*/
#include "MIDIUSB.h"

#define MIDI_CC_GENERAL1 10
#define MIDI_CC MIDI_CC_GENERAL1
#define MIDI_CHANNEL 3
#define NUM_OF_SLIDERS 5
#define NUM_OF_BUTTONS 2

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;
typedef struct {
  int pin;
  uint16_t value;
} SliderStore;

typedef struct {
  int value;
  int midi;
  int pin;
} LEDState;

enum ControlType {
  Slider,
  Button
};

//array of type SliderStore with NUM_OF_SLIDERS count
SliderStore oldAnalogValues[NUM_OF_SLIDERS] = {};
LEDState ledStates[NUM_OF_BUTTONS] = {};

int sliders[NUM_OF_SLIDERS] = {A0, A1, A2, A3, A9};
int buttons[NUM_OF_BUTTONS] = {5, 7};
int leds[NUM_OF_BUTTONS] = {6, 8};
Bounce bouncers[NUM_OF_BUTTONS] = {};
void setup() {
  for (int i = 0; i < NUM_OF_SLIDERS; i++) {
    int pin = sliders[i];
    pinMode(pin, INPUT);
    uint16_t analogValue = analogRead(pin);
    SliderStore oldValues = {pin , analogValue};
    oldAnalogValues[i] = oldValues;
  }

  for (int i = 0; i < NUM_OF_BUTTONS; i++) {
    int button = buttons[i];
    int ledPin = leds[i];

    pinMode(button, INPUT);
    pinMode(ledPin, OUTPUT);

    int midi = i + 0x44;

    LEDState led = {LOW, midi, ledPin};
    ledStates[i] = led;
    
    Bounce  bouncer  = Bounce(); 
    bouncer.attach(button);
    bouncer.interval(25);
    bouncers[i] = bouncer;
  }

  Serial.begin(9600);
}

void sendMidi(midiEventPacket_t midiCc) {
  MidiUSB.sendMIDI(midiCc);
  MidiUSB.flush();
}

void loop() {

  for (int i = 0; i < NUM_OF_BUTTONS; i++) {
    bouncers[i].update();
  }

  midiEventPacket_t rx;
  do {
    rx = MidiUSB.read();
    if (rx.header != 0) {
      unsigned long address = rx.byte2;
      int value = rx.byte3;

      for (int i = 0; i < NUM_OF_BUTTONS; i++) {
        LEDState ledState = ledStates[i];

        if (address == ledState.midi) {
          Serial.print("GOT MIDI: ");
          Serial.print(value);
          Serial.print("\n");

          int oldValue = ledState.value;
          int newValue = value == 127 ? HIGH : LOW;
          int pin = ledState.pin;

          ledStates[i] = { newValue, ledState.midi, pin};
          digitalWrite(pin, newValue);
        }
      }
    }
  } while (rx.header != 0);

  //probably should find a better way than a loop.
  for (int i = 0; i < NUM_OF_SLIDERS; i++) {
    SliderStore slider = oldAnalogValues[i];

    int oldAnalogValue = slider.value;
    int pin = slider.pin;

    int analogValue = analogRead(pin);
    int newAnalogValue = analogValue >> 3;

    if (newAnalogValue != oldAnalogValue) {
      midiEventPacket_t midiCc = {0x0B, 0xB0 | 0, i + 0x1A, newAnalogValue};
      sendMidi(midiCc);

      oldAnalogValues[i] = { pin, newAnalogValue };

      Serial.print(i);
      Serial.print(" slider: ");
      Serial.println(newAnalogValue);
    }
  }

  for (int i = 0; i < NUM_OF_BUTTONS; i++) {
    Bounce bouncer = bouncers[i];
    int button = buttons[i];
    int rawDigitalRead = digitalRead(button);
    
    if (bouncer.rose()) {

      LEDState ledState = ledStates[i];

      //inverse the state of the LED if button pressed
      int state = ledState.value == HIGH ? LOW : HIGH;

      midiEventPacket_t midiCc = {0x0B, 0xB0 | 0, ledState.midi, 127};
      sendMidi(midiCc);

      ledStates[i] = { state, ledState.midi, ledState.pin};
      digitalWrite(ledState.pin, state);

      Serial.print(i);
      Serial.print(" button: ");
      Serial.println("sending toggle");
    }
  }

}
