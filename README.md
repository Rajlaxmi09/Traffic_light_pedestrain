# Traffic_light_pedestrain
#  Arduino Traffic Light System with Pedestrian Button

This is a simple Arduino-based traffic light system with a pedestrian crossing feature. When a pedestrian presses the button, the system safely stops traffic and allows crossing. Built and simulated on Tinkercad.

## Features

- Simulates a real-world traffic light sequence.
- Pedestrian crossing button using a push button.
- Uses internal pull-up resistor for button input.
- Controlled timing for red, yellow, and green lights.

##  Components Used

- 1 × Arduino Uno
- 1 × Push Button
- 1 × Red LED
- 1 × Yellow LED
- 1 × Green LED
- 3 × 220Ω Resistors
- Breadboard & Jumper Wires

##  How It Works

- Normal Cycle: Red → Green
- When Button Pressed:
  → Red holds for a longer time  
  → Yellow turns on as a warning  
  → Green delays until pedestrian safely crosses  
- Uses `INPUT_PULLUP` to detect a LOW signal when the button is pressed.
  
## The code and screenshot of the circuit are attached .
##code:
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

## Screenshot
![traffic_light](https://github.com/user-attachments/assets/1bc7fb87-3635-49ee-845d-65b7ac18d187)



