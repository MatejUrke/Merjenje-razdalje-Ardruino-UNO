#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

#define echoPin 8 
#define trigPin 9 

#define led1 A0 
#define led2 A1
#define led3 A2 
#define led4 A3 
#define led5 A4 
#define led6 A5 

float time;
float distance_cm;

 
void setup(){
// put your setup code here, to run once:
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);
pinMode(led5, OUTPUT);
pinMode(led6, OUTPUT);

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



if(distance_cm<60){digitalWrite(led6, HIGH);}
else{digitalWrite(led6, LOW);}

if(distance_cm<50){digitalWrite(led5, HIGH);}
else{digitalWrite(led5, LOW);}

if(distance_cm<40){digitalWrite(led4, HIGH);}
else{digitalWrite(led4, LOW);}

if(distance_cm<30){digitalWrite(led3, HIGH);}
else{digitalWrite(led3, LOW);}

if(distance_cm<20){digitalWrite(led2, HIGH);}
else{digitalWrite(led2, LOW);}

if(distance_cm<10){digitalWrite(led1, HIGH);}
else{digitalWrite(led1, LOW);}

delay(200);
}

