
 
// incluimos la libreria apara manejo del motor paso a paso 
#include <Stepper.h>
 
// numero de pasoa del motor 
#define STEPS 100
 //pines en los cuales se conecta usando L293D
Stepper stepper(STEPS, 8, 9, 10, 11);
 
const int button =  4; // control de direccion motor paso a paso 
const int Pulsador2= 7; // boton de de confirmación de llenado 
const int giroA= 2;
const int giroB= 3;
int estado1;
int estado2;
void setup()
{
  pinMode(giroA, OUTPUT);
  pinMode(giroB, OUTPUT);
  pinMode(Pulsador2, INPUT_PULLUP);
  pinMode(button, INPUT_PULLUP);

  
  digitalWrite(giroA, LOW);
  digitalWrite(giroB, LOW);
  
  stepper.setSpeed(5);
}
 
int direction_ = 1;
 
void loop()
{
  estado1=digitalRead(button);
  estado2=digitalRead(Pulsador2);
  
  if ( digitalRead(button) == 0 )  // if button is pressed
    if ( debounce() )  // debounce button signal
    {
      direction_ *= -1;  // reverse direction variable
      while ( debounce() ) ;  // wait for button release
      
    }
 
  //direccion de mov motor paso a paso 
  stepper.step(direction_);

  if ( digitalRead(Pulsador2) == 0 )  // if button is pressed
    if ( debounce() )  // debounce button signal
    {
      direction_ *= -1;  // reverse direction variable
      while ( debounce() ) ;  // wait for button release
      
    }
     


   if(estado1==HIGH){
   digitalWrite(giroA, HIGH);
   digitalWrite(giroB, LOW);
}
  else if (button==HIGH){
  digitalWrite(giroA, LOW);
  digitalWrite(giroB, HIGH);
}
  else {
   digitalWrite(giroA, LOW);
   digitalWrite(giroB, LOW);
}
}

  

 
// a small function for button debounce
bool debounce()
{
  byte count = 0;
  for(byte i = 0; i < 5; i++) {
    if (digitalRead(button) == 0)
      count++;
    delay(100);
  }
  if(count > 2)  return 1;
  else           return 0;

  byte cont = 0;
  for(byte i = 0; i < 5; i++) {
    if (digitalRead(Pulsador2) == 0)
      cont++;
    delay(100);
  }
  if(cont > 2)  return 1;
  else           return 0;

}


////////////////////////////////////////////////
//const int Pulsador1=2;
//const int Pulsador2=3;
//const int giroA=4;
//const int giroB=5;
//int estado1;
//int estado2;
//
//void setup() {
//  // put your setup code here, to run once:
//pinMode(giroA, OUTPUT);
//pinMode(giroB, OUTPUT);
//pinMode(Pulsador1, INPUT);
//pinMode(Pulsador2, INPUT);
//
//digitalWrite(giroA, LOW);
//digitalWrite(giroB, LOW);
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//estado1=digitalRead(Pulsador1);
//estado2=digitalRead(Pulsador2);
//
//if(estado1==HIGH){
//digitalWrite(giroA, HIGH);
//digitalWrite(giroB, LOW);
//}
//else if (estado2==HIGH){
//digitalWrite(giroA, LOW);
//digitalWrite(giroB, HIGH);
//}
//else {
//digitalWrite(giroA, LOW);
//digitalWrite(giroB, LOW);
//}
//}
