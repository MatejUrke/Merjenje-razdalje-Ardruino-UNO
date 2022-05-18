#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

#define echoPin 8 
#define trigPin 9 


float time;
float distance_cm;

 
void setup(){

Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
 

lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print(" Welcome To ");
  lcd.setCursor(0,1);
  lcd.print("uros in matej");
delay(1000);
lcd.clear();
}
 
void loop(){

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);

time = pulseIn(echoPin, HIGH);

distance_cm = (time/2) / 29.1; 


lcd.setCursor(0, 0);
lcd.print("    razdalja   ");

lcd.setCursor(0, 1);
lcd.print(distance_cm,1);
lcd.print(" cm ");


Serial.print("cm= ");
Serial.print(distance_cm);

delay(200);
}

