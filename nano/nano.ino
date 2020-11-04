#include <MIDI.h>

#define A0 2
#define A1 3
#define A2 4
#define A3 5
#define A4 6
#define A5 7
#define A6 8
#define A7 9

int octavas = 5;
int cnt = 2;
int Tmax = 1000;
int Tmin = 10;
float paso = (Tmax - Tmin)/100000.0;

unsigned long previousMillis = 0;
float interval = 1000.0;
int ledState = LOW;

MIDI_CREATE_DEFAULT_INSTANCE();

void setup() 
{
  Serial.begin(9600);

  //MIDI.begin(MIDI_CHANNEL_OFF);
  
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);

  pinMode(11,INPUT_PULLUP);
  pinMode(12,INPUT_PULLUP);
}

void loop() 
{
  int subir = digitalRead(11); //blanco
  int bajar = digitalRead(12); //rojo
  
  unsigned long currentMillis = millis();
  
  if (!subir && interval < Tmax) {
    interval = interval+paso;
  }
  if (!bajar && interval > Tmin) {
    interval = interval-paso;
  }

  //Serial.println(paso);
  //Serial.println(interval);
  
  if (currentMillis - previousMillis >= interval) {
    
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    //Serial.println(analogRead(cnt));
    int potentiometer = analogRead(cnt);
    int nota = map(potentiometer, 0, 1023, 0, (octavas*12)-1);
    //Serial.println(nota);

    if (cnt == 2) {
      digitalWrite(cnt, HIGH);
      digitalWrite(9, LOW);
     }
    else {
      digitalWrite(cnt, HIGH);
      digitalWrite(cnt-1, LOW);
    }
    cnt++;
    
    /*// if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;  
      Serial.println(nota);
      //MIDI.sendNoteOn(nota, 127, 1);
    } else {
      ledState = LOW;
      //MIDI.sendNoteOff(nota, 0, 1);
    }

    // set the LED with the ledState of the variable:
    digitalWrite(cnt, ledState);
    if (ledState == LOW) {
      cnt++;
    }*/
    
    //Serial.println(analogRead(A0));
    /*Serial.println(analogRead(A1));
    Serial.println(analogRead(A2));
    Serial.println(analogRead(A3));
    Serial.println(analogRead(A4));
    Serial.println(analogRead(A5));
    Serial.println(analogRead(A6));
    Serial.println(analogRead(A7));*/
    
    
  }

  if (cnt == 10) cnt = 2;

}
