
/* send value when analog value changes*/
#include "MIDIUSB.h"
 
#define MIDI_CC_GENERAL1 10
#define MIDI_CC MIDI_CC_GENERAL1
#define MIDI_CHANNEL 3
#define NUM_OF_SLIDERS 5
#define NUM_OF_BUTTONS 2

uint8_t oldAnalogValue = 0;

uint8_t newAnalogValue = 0;

typedef struct { 
  int pin;
  uint16_t value;
} SliderStore;

typedef struct { 
  int pin;
  int value;
  int ledPin;
} ButtonStore;

//array of type SliderStore with NUM_OF_SLIDERS count
SliderStore oldAnalogValues[NUM_OF_SLIDERS] = {};
ButtonStore oldDigitalValues[NUM_OF_BUTTONS] = {};

int sliders[NUM_OF_SLIDERS] = {A0, A1, A2, A3, A6};
int buttons[NUM_OF_BUTTONS] = {5, 7};
int leds[NUM_OF_BUTTONS] = {6, 8};

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
      
    int digitalValue = digitalRead(button);
    ButtonStore oldValues = {button , digitalValue, ledPin};
    oldDigitalValues[i] = oldValues;
  }

  Serial.begin(9600);  
}

uint8_t getValue(int pin) {
  for (int i = 0; i <= NUM_OF_SLIDERS; i++) {
    SliderStore oldValues = oldAnalogValues[i];
    if (oldValues.pin == pin) {
      return oldValues.value;
    }
  }
  return NULL;
}

int getButtonValue(int pin) {
  for (int i = 0; i <= NUM_OF_BUTTONS; i++) {
    ButtonStore oldValues = oldDigitalValues[i];
    if (oldValues.pin == pin) {
      return oldValues.value;
    }
  }
  return NULL;
}

void sendMidi(midiEventPacket_t midiCc) {
  MidiUSB.sendMIDI(midiCc);
  MidiUSB.flush();
}
 
void loop() {

  //probably should find a better way than a loop.
  for (int i = 0; i < NUM_OF_SLIDERS; i++) { 

    int pin = sliders[i];
    uint16_t analogValue = analogRead(pin);
    uint8_t newAnalogValue = analogValue >> 3;
    uint8_t oldAnalogValue = getValue(pin);

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
    int button = buttons[i];
    int rawPinRead = digitalRead(button);
    int newValue = rawPinRead >> 3;
    int oldValue = getButtonValue(button);
    

    if (newValue != oldValue) {
      ButtonStore oldButtonStore = oldDigitalValues[i];
     
      midiEventPacket_t midiCc = {0x0B, 0xB0 | 0, i + 0x44, newValue};
      sendMidi(midiCc);

      digitalWrite(oldButtonStore.ledPin, rawPinRead);
      oldDigitalValues[i] = { button, newValue, oldButtonStore.ledPin};

      Serial.print(i);
      Serial.print(" button: ");
      Serial.println(newValue);
    }
  }

}
