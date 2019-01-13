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
float channel;
int volume;

// Variables pour l'écran LCD 5110
LCD5110 lcd(A0,A1,A2,12,11);

extern unsigned char BigNumbers[];
extern unsigned char TinyFont[];

extern uint8_t splash[];
extern uint8_t signal5[];
extern uint8_t signal4[];
extern uint8_t signal3[];
extern uint8_t signal2[];
extern uint8_t signal1[];

int analogPin = 0;
int val = 0; 
int frequencyInt = 0;
float frequency = 0;
float previousFrequency = 0;
int signalStrength = 0;

// Définitions des constantes pour le clavier
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {3, 4, 5, 6}; // broches de rangées du clavier
byte colPins[COLS] = {7, 8, 9, 10}; // broches de colonnes du clavier

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  initScreen();
  showSplashScreen();
  
  Serial.begin(9600);
  
  Serial.println("\n\nSi4703_Breakout Commands");
  Serial.println("========================");
  Serial.println("+ -     Volume (max 15)");
  Serial.println("u d     Seek up / down");
  
  radio.powerOn();
  radio.setVolume(0);
}

void loop() {

  char key = keypad.getKey();

  // Si une touche du clavier est pressé
  if (key){
    Serial.println(key);

    switch (key) {
    
    case 'A': // monter la fréquence
      channel = radio.seekUp();
      displayInfo();
      break;

    case 'B': // descendre la fréquence
      channel = radio.seekDown();
      displayInfo();
      break;

    case 'C': // monter le volume
      volume ++;
      if (volume == 16) volume = 15;
      radio.setVolume(volume);
      displayInfo();
      break;
    
    case 'D': // descendre le volume
      volume --;
      if (volume < 0) volume = 0;
      radio.setVolume(volume);
      displayInfo();
      break;
    }
  }
  
  frequency = channel/10;
  
  lcd.clrScr();
  printFrequency(frequency);
  delay(50); 
  val = 0;
}

void displayInfo()
{
   Serial.print("Channel:"); Serial.print(channel); 
   Serial.print(" Volume:"); Serial.println(volume); 
}

void initScreen()
{
  lcd.InitLCD();
  lcd.setFont(BigNumbers);
  lcd.clrScr();
}

void showSplashScreen()
{
  lcd.drawBitmap(0, 0, splash, 84, 48);
  lcd.update();  
  delay(3000);
  lcd.clrScr();
  lcd.update();
}

void printFrequency(float frequency)
{
  String frequencyString = String(frequency,1);
  if(frequencyString.length() == 4)
  {
    lcd.setFont(BigNumbers);
    lcd.print(frequencyString,14,12);
    lcd.update();
  }
  else
  {
    lcd.setFont(BigNumbers);
    lcd.print(frequencyString,0,12);
    lcd.update();
  }
}
