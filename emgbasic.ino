/*
EMG Biofeedback

Plays a beep that corresponds in legnth to the reading received from an EMG sensor. 
The more tense the muscle becomes, the longer the beep legnth. 

Based on two Arduino examples by Tom Igoe
 
This example code is in the public domain.
 
 */

const int analogInPin = A0;  // Analog input pin

int sensorValue = 0;        // value read from the sensor

#define NOTE_C4 262 //defines the note as middle C

int melody = NOTE_C4; //sets variable to middle C

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);            

  // print the results to the serial monitor:
  Serial.print("sensor = " );                       
  Serial.println(sensorValue);      

  int noteDuration = (sensorValue); //states the note duration is the sensor reading
  tone(8, melody,noteDuration); //plays note for legnth of sensor reading on pin 8

  // to distinguish the notes, set a minimum time between them.
  // the note's duration + 30% seems to work well:
  int pauseBetweenNotes = noteDuration * 1.30;
  delay(pauseBetweenNotes);
  // stop the tone playing:
  noTone(8);
                    
}


