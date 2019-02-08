#include <dht.h>
#include <LiquidCrystal.h>
//#include <time.h>

#define trigPin 10
#define echoPin 13
#define DHT11_PIN 7
#define ledPin 8

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

dht DHT;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

}

  float s, n, duration, distance;
  float speed;
  
void loop() {

  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  speed = 331.4 + (0.606 * DHT.temperature) + (0.0124 * DHT.humidity);
  distance = (duration / 2) * (speed / 10000);

  s = abs((distance - n) * 4);
  n = distance;
  if (s >= 10){
    digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
    lcd.print(s);
    lcd.print(" cm/s");
    delay(125);
  }
  
   else {
    digitalWrite(ledPin, LOW);   // turn the LED on (HIGH is the voltage level)
    lcd.print(s);
    lcd.print(" cm/s");
    delay(125);
  }
  delay(125);
  lcd.clear();
}
