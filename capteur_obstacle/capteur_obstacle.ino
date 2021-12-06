#include <NewPing.h>

int trig=12;
int echo=11;
unsigned long int lecture_echo=0;
int distance= 0;


void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
 
}
void loop() {
  digitalWrite(trig, HIGH); //generalisation de l'impulsion trig//
  delay(2);
  digitalWrite(trig,LOW);
  lecture_echo= pulseIn(echo, HIGH); //lecture longueur d'onde//
  distance = (lecture_echo) *0.017 ;//convertion distance//
  Serial.print("temps ");
  Serial.println(lecture_echo);  
  Serial.print("distance ");
  Serial.println(distance);
  delay(60);
}
