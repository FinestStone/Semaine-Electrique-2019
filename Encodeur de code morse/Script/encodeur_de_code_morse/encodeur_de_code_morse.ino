/*
 * Encodeur de code morse
 * Comme son nom l'indique, ce programme permet de recevoir les coordonnées envoyées
 * avec un clavier alphanumérique de 16 touches, de les traduire et d'envoyer le signal
 * à émettre à l'avertisseur sonore.
 * 
 * Coordonnées des rangées : 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
 * Coordonnées des colonnes : AA, AB, AC, AD, BB, BC, BD, CC, CD, DD
 * 
 * Code et projet fortement inspiré du projet de Chris Weatherford
 * (https://www.instructables.com/id/Arduino-Morse-Code/) et de CRCibernetica
 * (https://www.instructables.com/id/Connecting-a-4-x-4-Membrane-Keypad-to-an-Arduino/)
 */

#include <Keypad.h>

// Définitions des constantes pour le clavier
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5}; // broches de rangées du clavier
byte colPins[COLS] = {6, 7, 8, 9}; // broches de colonnes du clavier

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// Définitions des constantes pour l'avertisseur sonore
int led   = 12;   // avertisseur sonore connecté à la broche D12
int audio = 10;   // output audio on pin 10
int note  = 1200; // music note/pitch

int dotLen    = 200;        // temps d'une impulsions courtes ('point') en ms
int dashLen   = dotLen * 3; // temps d'une impulsions longues ('trait') en ms
int elemPause = dotLen;     // temps de pause entre les impulsions
int spaces    = dotLen * 3; // temps de pause entre les charactères

void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT); // initialisation de la broche associé à la DEL
}
  
void loop(){
  char key = keypad.getKey();

  // Si une touche du clavier est pressé
  if (key){
    Serial.println(key);
    GetChar(key);
  }
}

// Point
void MorseDot()
{
  digitalWrite(led, HIGH);   // allumer la DEL
  tone(audio, note, dotLen); // jouer la note
  delay(dotLen);             // maintenir la note pour le délai prescrit
}

// Trait
void MorseDash()
{
  digitalWrite(led, HIGH);    // allumer la DEL
  tone(audio, note, dashLen); // jouer la note
  delay(dashLen);             // maintenir la note pour le délai prescrit
}

// Fin d'un charactère
void LightsOff(int delayTime)
{
  digitalWrite(led, LOW); // éteindre la DEL
  noTone(audio);          // arrêter de jouer la note
  delay(delayTime);       // pause
}

// Fonction d'encodage des caractères en code morse
void GetChar(char tmpChar)
{
  // Encodage selon la touche appuyée
  switch (tmpChar) {
    
    case 'A': // code morse: .-
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      break;
    
    case 'B': // code morse: -...
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      break;
    
    case 'C': // code morse: -.-.
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      break;
    
    case 'D': // code morse: -..
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      break;
    
    case '1': // code morse: .----
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      break;
    
    case '2': // code morse: ..---
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      break;
    
    case '3': // code morse: ...--
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      break;
    
    case '4': // code morse: ....-
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      break;
    
    case '5': // code morse: .....
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      break;
    
    case '6': // code morse: -....
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      break;
    
    case '7': // code morse: --...
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      break;
    
    case '8': // code morse: ---..
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      break;
    
    case '9': // code morse: ----.
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDot();
      LightsOff(elemPause);
      break;
    
    case '0': // code morse: -----
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      MorseDash();
      LightsOff(elemPause);
      break;
    
    default: // Si un caractère n'est pas trouvé
    LightsOff(spaces);      
  }
}
