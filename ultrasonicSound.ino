//this is a prototype for an alarm system that uses sound and LEDS

//ultrasonic pins
//pin which triggers ultrasonic sound - Trig 
int trigPin = 7;
//pin which delivers time to receive echo 
int echoPin = 6;

//LEDS
int ledGreen=3;
int ledRed=4;
int ledBlue=5;

//buzzer 
int buzzer= 8;
int sound = 250;


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(buzzer, OUTPUT);
 
}

void loop() {

  // raw duration in milliseconds, cm is the
  // converted amount into a distance
  long duration, distance;
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
 

   if (distance <10){
    digitalWrite(ledRed, HIGH);
        sound = 300;
} 
else{
    digitalWrite(ledRed, LOW); 
}

   if (distance <15) {
        sound = 280;
        digitalWrite(ledBlue, HIGH);
}
else{
  digitalWrite(ledBlue, LOW);
}

  if (distance <30) {
    sound = 260;
       digitalWrite(ledGreen, HIGH);
}
else{
  digitalWrite(ledGreen, LOW);
}



 if (distance > 30 || distance <=0){
    Serial.println("Out of range");
    noTone(buzzer);
    
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    tone(buzzer, sound);
      
   
  }
  delay(300);
}
/*
initially from 
http://www.instructables.com/id/Arduino-Distance-Detector-with-a-Buzzer-and-LEDs/
*/
