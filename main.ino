#include <NewPing.h>

#define TRIGGER_PIN1 2
#define ECHO_PIN1 3
#define TRIGGER_PIN2 4
#define ECHO_PIN2 5
#define LED_PIN1 6
#define LED_PIN2 7

#define MAX_DISTANCE 20

NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE);
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE);

void setup() {
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  delay(50);
  unsigned int distance1 = sonar1.ping_cm();
  unsigned int distance2 = sonar2.ping_cm();
  Serial.print("Distance 1: ");
  Serial.print(distance1);
  Serial.print(" cm");
  Serial.print("\t Distance 2: ");
  Serial.print(distance2);
  Serial.println(" cm");
  if (distance1 < MAX_DISTANCE) {
    digitalWrite(LED_PIN1, HIGH);
  } else {
    digitalWrite(LED_PIN1, LOW);
  }
  if (distance2 < MAX_DISTANCE) {
    digitalWrite(LED_PIN2, HIGH);
  } else {
    digitalWrite(LED_PIN2, LOW);
  }
}
