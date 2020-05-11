#include <LiquidCrystal.h> // Libreria para que funcione el LCD

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 1, d7 = 0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);// Pines para la pantalla LCD 

// Definición de pines
const int nivel1 = 3;
const int nivel2 = 2;

void setup() {
  // Definición de entradas
  pinMode (nivel1, INPUT);
  pinMode (nivel2, INPUT);
  lcd.begin(16, 2); // Indicamos cual es la proporción de nuestro LCD
   
}

void loop() {
  lcd.print("Holi");
  if (nivel1 == HIGH && nivel2 == HIGH){
    lcd.clear();
    lcd.setCursor(0, 1); // Usamos la segunda linea
    lcd.print("Beaker casi vacio."); 
    delay(2000);
    lcd.clear();
  }
  if (nivel1 == LOW && nivel2 == HIGH){
    lcd.clear();
    lcd.setCursor(0, 1); // Usamos la segunda linea
    lcd.print("Beaker lleno."); 
    delay(2000);
    lcd.clear();
  }
}
