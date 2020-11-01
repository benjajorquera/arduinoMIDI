//#include <Adafruit_MCP4725.h>
#include <MIDI.h>  // Add Midi Library

MIDI_CREATE_DEFAULT_INSTANCE();

//int inmidi[]={};
//int j=1;

#define noteon 3
#define noteoff 2

//Adafruit_MCP4725 dac;

void setup() {
//Wire.begin();
//Serial.begin(9600);
pinMode(noteoff,OUTPUT);
pinMode(noteon,OUTPUT);
//dac.begin(0x60);      //Pitch
//dac.setVoltage(1000,false);
//dac.begin(0x61);      //Volume
//dac.setVoltage(1000,false);

MIDI.begin(MIDI_CHANNEL_OMNI); // Initialize the Midi Library.
  // OMNI sets it to listen to all channels.. MIDI.begin(2) would set it 
  // to respond to notes on channel 2 only.
MIDI.setHandleNoteOn(MyHandleNoteOn); // This is important!! This command
  // tells the Midi Library which function you want to call when a NOTE ON command
  // is received. In this case it's "MyHandleNoteOn".
MIDI.setHandleNoteOff(MyHandleNoteOff); // This command tells the Midi Library 
  // to call "MyHandleNoteOff" when a NOTE OFF command is received.
}

void loop() {
  
  MIDI.read();
  
}

void MyHandleNoteOn(byte channel, byte pitch, byte velocity) { 
  digitalWrite(noteon,HIGH);
  digitalWrite(noteoff,LOW);
  //dac.begin(0x60);
  //dac.setVoltage(pitch*68,false);
  //dac.begin(0x61);
  //dac.setVoltage(500*velocity,false);

}

void MyHandleNoteOff(byte channel, byte pitch, byte velocity) { 
  digitalWrite(noteon,LOW);
  digitalWrite(noteoff,HIGH);
  //dac.begin(0x61);
  //dac.setVoltage(0,false);

}
