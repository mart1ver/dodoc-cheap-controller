//dodoc controller v1 martin vert

#include "DigiKeyboard.h"

 char* LeftChar = "w";  //caractere renvoyé par la fleche de gauche (assumes US-style keyboard)
 char* RightChar = "s"; //caractere renvoyé par la fleche de droite (assumes US-style keyboard)
 char* SquareChar =  "a"; //caractere renvoyé par le carré rouge (assumes US-style keyboard)
 

void setup() {
  pinMode(0, INPUT_PULLUP);// fleche de gauche cablée sur PB0, INPUT_PULLUP, bouton poussoir directement cablé entre cette entrée et la masse, pas besoin de resistance de pull up supplémentaire 
  pinMode(2, INPUT_PULLUP);// fleche de gauche cablée sur PB2 INPUT_PULLUP, bouton poussoir directement cablé entre cette entrée et la masse, pas besoin de resistance de pull up supplémentaire 
  pinMode(1, INPUT);       // carré rouge cablé sur PB1, INPUT simple mais pas besoin de resistance de pull up supplémentaire (présente onboard avec une led en serie), permet l'utilisation de la led à l'appui sur le boutton
}

void loop() {
 
 // lecture de l'etat des boutons 
  int LeftVal = digitalRead(0);
  int RightVal = digitalRead(2);
  int SquareVal = digitalRead(1);
  
 // prevent missing the first character after a delay:
  DigiKeyboard.sendKeyStroke(0);
  
 // Type out this string letter by letter on the computer (assumes US-style keyboard)
    if (LeftVal == LOW) {
   DigiKeyboard.print(LeftChar);
  }
    if (RightVal == LOW) {
   DigiKeyboard.print(RightChar);
  }  
    if (SquareVal == HIGH) {
   DigiKeyboard.print(SquareChar);
  }

 // It's better to use DigiKeyboard.delay() over the regular Arduino delay()
 // if doing keyboard stuff because it keeps talking to the computer to make
 // sure the computer knows the keyboard is alive and connected
  DigiKeyboard.delay(200);
}
