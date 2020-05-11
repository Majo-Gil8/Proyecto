#include <Keypad.h> // Libreria para el teclado
#include <LiquidCrystal.h> // Libreria para el LCD

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 1, d7 = 0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const byte Filas = 4;
const byte Columnas = 4;
char Teclas [Filas][Columnas] = {
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'c','0','=','+'}
};
byte FilasPin[Filas] = {2,3,4,5}; // Pines a los que estan conectadas las filas
byte ColumnasPin[Columnas] = {6,7,8,9}; // Pines a los que estan conectadas las columnas
int i = 0;
int vialTotal = 0;
char puls = 0;
char arr[10];
String vial = "";
String vial1 = "";
Keypad keypad = Keypad(makeKeymap (Teclas), FilasPin, ColumnasPin, Filas, Columnas);

void setup() {
  lcd.begin(20,4); // Tamaño de la LCD

}

void loop() {

  switch (i){
  
    case 0:
  
        lcd.setCursor(8,1);
        lcd.print(" Oreo ");
        delay(1000);
        lcd.clear();
        
    while (puls != 'c'){
      
        lcd.setCursor(6,0);
        lcd.print(" Presiona c ");
        lcd.setCursor(5,1);
        lcd.print(" para comenzar ");
        puls = keypad.getKey(); 
        
    }
    lcd.clear();
    i = 1;
    break; 
    
    case 1: // Selecciona jeringa
        puls = 0;
    while (puls == 0){
        
        lcd.setCursor(4,0);
        lcd.print("Selecciona una ");
        lcd.setCursor(10,1);
        lcd.print("jeringa ");
      
        lcd.setCursor(1,2);
        lcd.print("Opcion 1");
        lcd.setCursor(10,2);
        lcd.print("presiona 1");
      
        lcd.setCursor(1,3);
        lcd.print("Opcion 2");
        lcd.setCursor(10,3);
        lcd.print("presiona 2");
        puls = keypad.getKey();
        
     }
    
  
      if (puls == '1'){ // Jeringa de insulina (1ml)
        lcd.clear();
        lcd.setCursor(2,0);
        lcd.print("Selecciono 1");
        puls = keypad.getKey();
        delay(1000);
        
      }
       else if (puls == '2'){ // Jeringa de 4ml
         lcd.clear();
         lcd.setCursor(2,0);
         lcd.print("Selecciono 2");
         puls = keypad.getKey();
         delay(1000);
          
       }
      
      lcd.clear();
      i = 2;
      break;

      case 2: // Selecciona volumen
           puls = 0;
         while (puls == 0){
          
            lcd.setCursor(4,0);
            lcd.print("Selecciona un ");
            lcd.setCursor(10,1);
            lcd.print(" volumen ");

            // Jeringa de 4 ml
            lcd.setCursor(0,1);
            lcd.print("Oprime:");
            lcd.setCursor(0,2);
            lcd.print("1 = 0.5");
            lcd.setCursor(10,2);
            lcd.print("2 = 1.0");
            lcd.setCursor(0,3);
            lcd.print("3 = 1.5");
            lcd.setCursor(10,3);
            lcd.print("4 = 2.0");
            puls = keypad.getKey();
            
           }
            
           if (puls == '1'){
            lcd.clear();
            lcd.setCursor(2,0);
            lcd.print("Selecciono 0.5 ml");
            puls = keypad.getKey();
            delay(1000);
        
            }
           else if (puls == '2'){
            lcd.clear();
            lcd.setCursor(2,0);
            lcd.print("Selecciono 1.0 ml");
//            puls = keypad.getKey();
            delay(1000);
          
            }
           else if (puls == '3'){
            lcd.clear();
            lcd.setCursor(2,0);
            lcd.print("Selecciono 1.5 ml");
            puls = keypad.getKey();
            delay(1000);  
            }
           else if (puls == '4'){
            lcd.clear();
            lcd.setCursor(2,0);
            lcd.print("Selecciono 2.0 ml");
            puls = keypad.getKey();
            delay(1000);
            }
      lcd.clear();
      i = 3;
      break;

         puls = 0;
         while (puls == 0){// Jeringa de 1 ml

            lcd.setCursor(4,0);
            lcd.print("Selecciona un ");
            lcd.setCursor(10,1);
            lcd.print(" volumen ");
            lcd.setCursor(0,1);
            
            lcd.print("Oprime:");
            lcd.setCursor(0,2);
            lcd.print("5 = 0.2");
            lcd.setCursor(10,2);
            lcd.print("6 = 0.5");
            lcd.setCursor(0,3);
            lcd.print("7 = 0.7");
            lcd.setCursor(10,3);
            lcd.print("8 = 0.9");
            puls = keypad.getKey();

            }
            
           if (puls == '5'){
            lcd.clear();
            lcd.setCursor(2,0);
            lcd.print("Selecciono 0.2 ml");
            puls = keypad.getKey();
            delay(1000);
        
            }
           else if (puls == '6'){
            lcd.clear();
            lcd.setCursor(2,0);
            lcd.print("Selecciono 0.5 ml");
            puls = keypad.getKey();
            delay(1000);
          
            }
           else if (puls == '7'){
            lcd.clear();
            lcd.setCursor(2,0);
            lcd.print("Selecciono 0.7 ml");
            puls = keypad.getKey();
            delay(1000);  
            }
           else if (puls == '8'){
            lcd.clear();
            lcd.setCursor(2,0);
            lcd.print("Selecciono 0.9 ml");
            puls = keypad.getKey();
            delay(1000);
            }

      lcd.clear();
      i = 3;
//      break;

      case 3:  // Selecciona vial

       puls = 0;
       vial = "";
         while (puls == 0){
          
            lcd.setCursor(0,0);
            lcd.print("Selecciona el vial ");
            lcd.setCursor(4,1);
            lcd.print("entre 01 y 12 ");

            }
       
            lcd.clear();
            vial += puls;
            lcd.setCursor(0,0);
            lcd.print("Vial:");
            lcd.setCursor(0,2);
            lcd.print(vial.toInt());

            puls = 0;
            vial1 = "";
            vial1 = vial1.toInt(); 
            while(puls == 0 ){
              
            puls = keypad.getKey();
            
            }
            
//            vial1 += puls;
//            lcd.setCursor(1,2);
//            lcd.print(vial1.toInt());
//            delay(1000);
//            lcd.clear();
//            lcd.setCursor(2,2);
//            vialTotal= (int)(vial.toInt()*10) + (int)(vial1.toInt()); 
//            lcd.print(vial1); 
//            delay (1000);
//
//          if(vialTotal=0 || vialTotal>12){
//            
//            lcd.clear();
//            
//            lcd.setCursor(4,0);
//            lcd.print("Vial");
//            lcd.setCursor(4,1);
//            lcd.print("incorrecto");
//            delay(1000);
//            
//            }
      lcd.clear();
      i = 4;
//      break;
  }
}
