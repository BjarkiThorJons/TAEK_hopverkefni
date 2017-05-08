        #include <Servo.h>
Servo myservo;
#define trigPin 13
#define echoPin 12
#define led 11
int takkapinni=3;
int teljarinn=2;
int pos=0;
int snua=0;
int xPosition=0;
int xPin=A1;
int takki=HIGH;

void setup() {
  myservo.attach(9);
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(takkapinni, INPUT_PULLUP);
  pinMode(xPin, INPUT);
}

void loop() {
  takki = digitalRead(takkapinni);
  if (takki==LOW){
    teljarinn++;
    }
    xPosition = analogRead(xPin);
    if(teljarinn%2==0){
      Serial.println(snua);
      Serial.print("Position: ");
      Serial.println(pos);
    if (pos==180){
      snua=1;
    }else if (pos==0){
      snua=0;
    }if (snua==0) {
      pos+=4;           
    }else{ 
      pos-=4;
    }
  }
    if (teljarinn%2!=0){
       if (xPosition>600){
          pos+=4;}
      if (xPosition<400){
          pos-=4;
        }
        Serial.print("X: ");
        Serial.println(xPosition);
      }
    
    myservo.write(pos);  
  
  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance <= 20) { 
    digitalWrite(led,HIGH);
  }
    

  else{
    digitalWrite(led,LOW );
    }
    //Serial.print(distance);
    //Serial.println("cm");
    //Serial.println(pos);
    //Serial.println(takki);
    //Serial.println(teljarinn);
 
  delay(100);
}
