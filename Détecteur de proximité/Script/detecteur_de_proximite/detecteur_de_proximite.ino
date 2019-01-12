/*
 * Détecteur de proximité
 * Petit programme qui permet d'évaluer la distance qui sépare le sonar d'une surface plane qui lui 
 * fait face. Un avertisseur sonore est également utilisé pour émettre un son. La fréquence émise 
 * varie selon la distance mesurée.
 * 
 * Code et projet fortement inspiré du projet d'edelbluth 
 * (https://github.com/arobito/arobito-mcu/tree/master/experiments/usonic/Basic_Distance_Measuring)
 */

#define TRIGGER_PIN 13
#define ECHO_PIN 12
#define USONIC_DIV 58.0
#define MEASURE_SAMPLE_DELAY 5
#define MEASURE_SAMPLES 25
#define MEASURE_DELAY 250

void setup() {
  Serial.begin(9600);
  
  // Initialiser les broches « Trigger Output » et « Echo Input »
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  // Réinitialiser la broche « trigger » et attente d'une demi-seconde
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(500);
}

long singleMeasurement()
{
  long duration = 0;
  
  // Broche « trigger » haute pour mesurer
  digitalWrite(TRIGGER_PIN, HIGH);
  // Attente de 11 µs
  delayMicroseconds(11);
  // Broche « trigger » basse
  digitalWrite(TRIGGER_PIN, LOW);
  // Attente pour l'écho
  duration = pulseIn(ECHO_PIN, HIGH);
  return (long) (((float) duration / USONIC_DIV) * 10.0);
}

long measure()
{
  long measureSum = 0;
  for (int i = 0; i < MEASURE_SAMPLES; i++)
  {
    delay(MEASURE_SAMPLE_DELAY);
    measureSum += singleMeasurement();
  }
  return measureSum / MEASURE_SAMPLES;
}

void loop()
{
  delay(MEASURE_DELAY);
  long distance = measure();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" mm");

  // Surface à une distance de 10 cm
  if(distance < 100)
  {
    tone(10, 3000, 100); // jouer la note
    delay(100);
  }

  // Surface à une distance de 25 cm
  else if(distance < 250)
  {
    tone(10, 2000, 200); // jouer la note
    delay(400);
  }

  // Surface à une distance de 50 cm
  else if(distance < 500)
  {
    tone(10, 1000, 400); // jouer la note
    delay(1000);
  }
}
