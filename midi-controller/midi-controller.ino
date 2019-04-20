
/* send value when analog value changes*/
#include "MIDIUSB.h"
 
#define MIDI_CC_GENERAL1 0x0E
#define MIDI_CC MIDI_CC_GENERAL1
#define MIDI_CHANNEL 3

uint8_t oldAnalogValue = 0;
uint8_t newAnalogValue = 0;

typedef struct { 
  uint8_t lang;
  int pin;
  uint16_t value;
} valueDictionary;

valueDictionary oldAnalogValues[] = {0, 0, 0};

int pins[5] = {A0, A1, A2, A3, A4};

void setup() {
  for (int i = 0; i < sizeof(pins); i++) {
    int pin = pins[i];
    pinMode(pin, INPUT);
    uint16_t analogValue = analogRead(pin);
    oldAnalogValues[i].pin = pin;
    oldAnalogValues[i].value = analogValue;
  }
}
 
void loop() {

  //probably should find a better way than a loop.
  for (int i = 0; i < sizeof(pins); i++) { 
    int pin = pins[i];
    uint16_t analogValue = analogRead(pin);
    uint8_t newAnalogValue = analogValue >> 3;

    if (newAnalogValue != oldAnalogValue) {   
        byte channel = MIDI_CHANNEL;
        channel += 0xB0 - 1;
        if (channel >= 0xB0 && channel <= 0xBF) {
          midiEventPacket_t midiCc = {MIDI_CHANNEL, MIDI_CC + i, 0, newAnalogValue};
          MidiUSB.sendMIDI(midiCc);
          MidiUSB.flush();
          oldAnalogValue = newAnalogValue;
          
          Serial.print(i);
          Serial.print(": ");
          Serial.println(newAnalogValue);

        }
    }
  }
}
