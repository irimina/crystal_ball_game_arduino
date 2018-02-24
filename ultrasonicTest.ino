//ultrasonic test. 
//Measure distance to closest object and display on the screen


//ultrasonic pins
//pin which triggers ultrasonic sound - Trig 
int trigPin = 7;
//pin which delivers time to receive echo 
int echoPin = 6;


void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
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
  
    Serial.print(distance);
    Serial.println(" cm");
    delay(400);
    
}
