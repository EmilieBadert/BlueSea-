#include <NewPing.h>

int ENA=9; //enable pin Moteur A//
int avantA=4; //Marche  avant A//
int arriereA=5; //Marche arriere A//

int ENB=10; //enable pin B//
int avantB=6; //marche avant B//
int arriereB=7; //marche arrière B//


int trig=12;
int echo=11;
unsigned long int lecture_echo=0;
int distance= 0;

int moteurspeed=0; //initialisation vitesse des moteurs//
int longobstacle=50; //distance max autorisé à l'obstacle//


void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);

  pinMode(avantA, OUTPUT); //configuration des branches de sortie//
  pinMode(arriereA, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(avantB, OUTPUT);
  pinMode(arriereB, OUTPUT);
  pinMode(ENB, OUTPUT);

  digitalWrite(ENA,LOW); //Moteur A ne tourne pas//
  digitalWrite(ENB,LOW); //moteur B ne tourne pas//


  

  
}
void loop() {
  digitalWrite(trig, HIGH); //generalisation de l'impulsion trig//
  delay(2);
  digitalWrite(trig,LOW);
  lecture_echo= pulseIn(echo, HIGH); //lecture longueur d'onde//
  distance = (lecture_echo /2) *0.034 ;//convertion distance//
  Serial.print("temps ");
  Serial.println(lecture_echo);  
  Serial.print("distance ");
  Serial.println(distance);
  delay(60);

  moteurspeed=800; //definition de la vitesse des moteurs//
  if (distance>longobstacle){
    analogWrite(ENA,moteurspeed ); 
    digitalWrite(avantA, HIGH); 
    digitalWrite(arriereB, LOW);
    Serial.println("moteur A et B en marche avant"); 

    analogWrite(ENB, moteurspeed); 
    digitalWrite(avantB, HIGH); 
    digitalWrite(arriereB, LOW); 

    delay(100);
  }
  else {
    analogWrite(ENA,moteurspeed );  //Moteur A en marche arriere pour stopper le bateau//
    digitalWrite(avantA, LOW); 
    digitalWrite(arriereB, HIGH); 

    analogWrite(ENB, moteurspeed); //Moteur B en marhce arriere pur stopper le bateau//
    digitalWrite(avantB, LOW); 
    digitalWrite(arriereB, HIGH);
    Serial.println("moteurs A et B en marche arriere"); 

    delay(100); //a definir par test//
    
    analogWrite(ENA,moteurspeed ); 
    digitalWrite(avantA, HIGH); 
    digitalWrite(arriereB, LOW); 

    analogWrite(ENB, moteurspeed); 
    digitalWrite(avantB, LOW); 
    digitalWrite(arriereB, LOW); 

    delay(100);  // a definir par test//
  }
  
}
