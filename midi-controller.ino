
/* send value when analog value changes*/
#include "MIDIUSB.h"
 
uint8_t oldAnalogValue = 0;
uint8_t newAnalogValue = 0;

int pins[5] = [A0, A1, A2, A3, A4];

void setup() {
  for (int i = 0; i < pins.count; i++) {
    int pin = pins[i];
    pinMode(pin, INPUT);
  }
}
 
void loop() {
  uint16_t analogValue = analogRead(A0);
  uint8_t newAnalogValue = analogValue >> 3;
  
  if (newAnalogValue != oldAnalogValue)
  {   
    midiEventPacket_t midiCc = { 0x0B, 0xB0, 0, newAnalogValue };
    MidiUSB.sendMIDI(midiCc);
    MidiUSB.flush();
    oldAnalogValue = newAnalogValue;
  }
}
