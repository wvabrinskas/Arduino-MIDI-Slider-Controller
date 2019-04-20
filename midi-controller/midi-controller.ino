
/* send value when analog value changes*/
#include "MIDIUSB.h"
 
#define MIDI_CC_GENERAL1 10
#define MIDI_CC MIDI_CC_GENERAL1
#define MIDI_CHANNEL 3
#define NUM_OF_INPUTS 5

uint8_t oldAnalogValue = 0;

uint8_t newAnalogValue = 0;

typedef struct { 
  int pin;
  uint16_t value;
} valueStore;

valueStore oldAnalogValues[NUM_OF_INPUTS] = {};

int pins[NUM_OF_INPUTS] = {A0, A1, A2, A3, A6};

void setup() {
  for (int i = 0; i < NUM_OF_INPUTS; i++) {
    int pin = pins[i];
    pinMode(pin, INPUT);
    uint16_t analogValue = analogRead(pin);
    valueStore oldValues = {pin , analogValue};
    oldAnalogValues[i] = oldValues;
  }
  Serial.begin(9600);  
}

uint8_t getValue(int pin) {
  for (int i = 0; i <= NUM_OF_INPUTS; i++) {
    valueStore oldValues = oldAnalogValues[i];
    if (oldValues.pin == pin) {
      return oldValues.value;
    }
  }
  return NULL;
}
 
void loop() {

  //probably should find a better way than a loop.
  for (int i = 0; i < NUM_OF_INPUTS; i++) { 

    int pin = pins[i];
    uint16_t analogValue = analogRead(pin);
    uint8_t newAnalogValue = analogValue >> 3;
    uint8_t oldAnalogValue = getValue(pin);

    if (newAnalogValue != oldAnalogValue) {   
        midiEventPacket_t midiCc = {0x0B, 0xB0 | 0, i + 0x1A, newAnalogValue};
        MidiUSB.sendMIDI(midiCc);
        MidiUSB.flush();
        
        oldAnalogValues[i] = { pin, newAnalogValue };

        Serial.print(i);
        Serial.print(": ");
        Serial.println(newAnalogValue);

    }
  }
}
