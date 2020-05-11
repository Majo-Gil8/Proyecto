
//definición de variables- actuador lineal 
// archivo de proteus motor2 

const int Pulsador1=2;
const int Pulsador2=13;
const int giroA=4;
const int giroB=5;
int estado1;
int estado2;

void setup() {
pinMode(giroA, OUTPUT);
pinMode(giroB, OUTPUT);
pinMode(Pulsador1, INPUT);
pinMode(Pulsador2, INPUT);

digitalWrite(giroA, LOW);
digitalWrite(giroB, LOW);
}

void loop() {
// leer los estados de los puladores 
estado1=digitalRead(Pulsador1);
estado2=digitalRead(Pulsador2);

if(estado1==HIGH){
digitalWrite(giroA, HIGH);
digitalWrite(giroB, LOW);
}
else if (estado2==HIGH){
digitalWrite(giroA, LOW);
digitalWrite(giroB, HIGH);
}
else {
digitalWrite(giroA, LOW);
digitalWrite(giroB, LOW);
}
}
