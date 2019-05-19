/*
 * Construction d'une radio FM
 * Ce programme permet d'interfacer avec un module de réception FM. Il rend possible,
 * en branchant des écouteurs sur une puce Si403, l'écoute de la radio FM. Le clavier
 * alphanumérique permet de changer la station aisément et l'écran LCD 5110 de Nokia
 * affiche la station sélectionnée.
 * 
 * Code et projet fortement inspiré du travail de Nick Koumaris
 * (https://www.youtube.com/watch?v=7OMaf4L4Z3s) et du tutoriel de SparkFun
 * (https://learn.sparkfun.com/tutorials/si4703-fm-radio-receiver-hookup-guide/all)
 */

#include <Si4703_Breakout.h>
#include <Wire.h>
#include <LCD5110_Graph.h>
#include <Keypad.h>

// Variables du module Si4703
int resetPin = 2;
int SDIO = A4;
int SCLK = A5;
Si4703_Breakout radio(resetPin, SDIO, SCLK);

// Variables pour l'écran LCD 5110
LCD5110 lcd(A0,A1,A2,12,11);
extern unsigned char BigNumbers[];

// Variables pour le clavier
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {3, 4, 5, 6}; // Broches de rangées du clavier
byte colPins[COLS] = {7, 8, 9, 10}; // Broches de colonnes du clavier
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// Variables pour la fréquence et le poste écouté, ainsi que le volume choisi
float frequency = 0;
float channel = 0;
uint8_t volume = 0;

// Code pour l'initialisation de librairies
void setup() {
  // Initialisation de l'écran LCD
  lcd.InitLCD();
  lcd.setFont(BigNumbers);
  lcd.clrScr();

  // Initialisation du récepteur FM
  radio.powerOn();
  radio.setVolume(0);
}

void loop() {
  // Enregistrer la touche appuyée sur le clavier
  char key = keypad.getKey();

  // Si une touche du clavier a été appuyée
  if (key){
    switch (key) {
      // Monter la fréquence
      case 'A':
        channel = radio.seekUp();
        break;
      
      // Descendre la fréquence
      case 'B':
        channel = radio.seekDown();
        break;
      
      // Monter le volume
      case 'C':
        volume ++;
        if (volume == 16) volume = 15;
        radio.setVolume(volume);
        break;
      
      // Descendre le volume
      case 'D':
        volume --;
        if (volume < 0) volume = 0;
        radio.setVolume(volume);
        break;
    }
  }

  frequency = channel/10;

  // Rafraîchir l'écran
  lcd.clrScr();

  // Si la fréquence est inférieure à 99.9 MHz (3 caractères à afficher)
  if (String(frequency,1).length() == 4)
  {
    lcd.setFont(BigNumbers);
    lcd.print(String(frequency,1),14,12);
    lcd.update();
  }
  
  // Sinon, la fréquence est supérieure ou égale à 100.0 MHz (4 caractères à afficher)
  else
  {
    lcd.setFont(BigNumbers);
    lcd.print(String(frequency,1),0,12);
    lcd.update();
  }

  // Délai de 50 ms
  delay(50);
}
