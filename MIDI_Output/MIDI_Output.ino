#include <MIDI.h>
//#include <SevSeg.h>

#define PIN12 12

//SevSeg sevseg;
int flag = 0;

MIDI_CREATE_DEFAULT_INSTANCE();


// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

int ledState = LOW;   

void setup()
{

  pinMode(PIN12, INPUT);
  pinMode(9, OUTPUT);
  pinMode(2, OUTPUT);

  digitalWrite(9, LOW);
  
  MIDI.begin(MIDI_CHANNEL_OFF);

  /*byte numDigits = 3;
  byte digitPins[] = {9, 10, 11};
  byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 13};
  bool resistorsOnSegments = false;
  byte hardwareConfig = COMMON_CATHODE; 
  //sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);*/
}

void loop()
{
  
  //int nota = map(analogRead(A0), 0, 1023, 0, 36);

  // constants won't change:
  long interval = map(analogRead(A0), 0, 1023, 36, 0)*5;           // interval at which to blink (milliseconds)
  
  //sevseg.setNumber(nota); // Muestra la nota en el display
  //sevseg.refreshDisplay(); // Actualiza el display

  unsigned long currentMillis = millis();
  
  while (currentMillis - previousMillis >= interval) {
    
    interval = map(analogRead(A0), 0, 1023, 36, 0)*5;
    
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    if(ledState == HIGH){
      noteOn(60, 127);
      }
     else {
      noteOff(60, 0);
      }
     digitalWrite(2, ledState);
  }

  
  /*if (digitalRead(PIN12) && flag == 0) {
    noteOn(nota, 127);
    flag = 1;
  }

  else if (!digitalRead(PIN12) && flag == 1) {
    noteOff(nota, 0);
    flag = 0;
  }*/
  

}

void noteOn(int note, int pressure) {
  MIDI.sendNoteOn(note, pressure, 1);
}

void noteOff(int note, int pressure) {
  MIDI.sendNoteOff(note, pressure, 1);
}
