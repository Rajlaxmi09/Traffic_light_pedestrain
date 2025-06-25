#define LED_PIN_RED 12
#define LED_PIN_YELLOW 11
#define LED_PIN_GREEN 10
#define BUTTON_PIN 2
bool pedestrianRequested = false;

void setup(){
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN_RED , OUTPUT);
  pinMode(LED_PIN_YELLOW , OUTPUT);
  pinMode(LED_PIN_GREEN , OUTPUT);
}

void loop(){
  if (digitalRead(BUTTON_PIN) == LOW) {
    pedestrianRequested = true;
  }

  digitalWrite(LED_PIN_RED, HIGH);
  delay(5000);
  digitalWrite(LED_PIN_RED, LOW);

  if (pedestrianRequested) {
    digitalWrite(LED_PIN_YELLOW, HIGH);
    delay(2000);
    digitalWrite(LED_PIN_YELLOW, LOW);
    digitalWrite(LED_PIN_RED, HIGH); // Stop traffic
    delay(4000); // Pedestrian crosses
    digitalWrite(LED_PIN_RED, LOW);
    pedestrianRequested = false;
  }

  digitalWrite(LED_PIN_GREEN, HIGH);
  delay(5000);
  digitalWrite(LED_PIN_GREEN, LOW);
}


