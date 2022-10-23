#include <Arduino.h>
#include <BLEMidi.h>

#define RXD2 16
#define TXD2 17


void onNoteOn(uint8_t channel, uint8_t note, uint8_t velocity, uint16_t timestamp)
{
  Serial.printf("Note on : channel %d, note %d, velocity %d (timestamp %dms)\n", channel, note, velocity, timestamp);

    noteOn(channel, note, velocity);
}

void onNoteOff(uint8_t channel, uint8_t note, uint8_t velocity, uint16_t timestamp)
{
  Serial.printf("Note off : channel %d, note %d, velocity %d (timestamp %dms)\n", channel, note, velocity, timestamp);
   
   noteOn(channel, note, velocity);
  
}

void onAfterTouchPoly(uint8_t channel, uint8_t note, uint8_t pressure, uint16_t timestamp)
{
  Serial.printf("Polyphonic after touch : channel %d, note %d, pressure %d (timestamp %dms)\n", channel, note, pressure, timestamp);
}

void onControlChange(uint8_t channel, uint8_t controller, uint8_t value, uint16_t timestamp)
{
    Serial.printf("Control change : channel %d, controller %d, value %d (timestamp %dms)\n", channel, controller, value, timestamp);
}

void onProgramChange(uint8_t channel, uint8_t program, uint16_t timestamp)
{
    Serial.printf("Program change : channel %d, program %d (timestamp %dms)\n", channel, program, timestamp);
}

void onAfterTouch(uint8_t channel, uint8_t pressure, uint16_t timestamp)
{
    Serial.printf("After touch : channel %d, pressure %d (timestamp %dms)\n", channel, pressure, timestamp);
}

void onPitchbend(uint8_t channel, uint16_t value, uint16_t timestamp)
{
    Serial.printf("Pitch bend : channel %d, value %d (timestamp %dms)\n", channel, value, timestamp);
}



void setup() {
  Serial.begin(115200);
  Serial2.begin(31250);
  BLEMidiServer.begin("MIDI device");
  BLEMidiServer.setOnConnectCallback([]() {
    Serial.println("Connected");
  });
  BLEMidiServer.setOnDisconnectCallback([]() {
    Serial.println("Disconnected");
  });
  BLEMidiServer.setNoteOnCallback(onNoteOn);
  BLEMidiServer.setNoteOffCallback(onNoteOff);
  BLEMidiServer.setAfterTouchPolyCallback(onAfterTouchPoly);
  BLEMidiServer.setControlChangeCallback(onControlChange);
  BLEMidiServer.setProgramChangeCallback(onProgramChange);
  BLEMidiServer.setAfterTouchCallback(onAfterTouch);
  BLEMidiServer.setPitchBendCallback(onPitchbend);
  //BLEMidiServer.enableDebugging();
}

void loop() {
   
}


void noteOn(int cmd, int pitch, int velocity) {
  Serial2.write(cmd);
  Serial2.write(pitch);
  Serial2.write(velocity);
}
