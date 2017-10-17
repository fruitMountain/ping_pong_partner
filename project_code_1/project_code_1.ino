//seth berryhill
//oct 13, 2016
//proto1 code for me223 group project

// code will connect 2 motors constantly spinning at the same speed, controlled with pot
// and also 2 servos used as a gate to feed out ping pong balls

// A2212/13T 1000KV is the motor

#include <Servo.h>

int motor1 = 4;
int motor2 = 6;
int servo1Pin = 8;
int servo2Pin = 10;
int aimPin = 12;

int potPin = 0;
int motorValue;

Servo gate1;
Servo gate2;
Servo aim;


void setup(){
Serial.begin(9600);

 pinMode(motor1, OUTPUT);
 pinMode(motor2, OUTPUT);

 gate1.attach(servo1Pin);
 gate2.attach(servo2Pin);

 aim.attach(aimPin);
 aim.write(0);

}


void loop(){
 //spinMotors();
 servoGate();
 aimServo();
}


void spinMotors(){
  //reads a pot and writes that speed to both motors

 motorValue = analogRead(potPin);

 digitalWrite(motor1, motorValue);
 Serial.println(motorValue);
}


void servoGate(){
  //opens and closes servo1, waits 5 seconds, then opens and closes servo2

  int closed = 90;
  int open = 0;

  gate1.write(closed);
  gate2.write(closed);

  gate1.write(open);
  delay(250);
  gate1.write(closed);

  delay(2500);

  gate2.write(open);
  delay(350);
  gate2.write(closed);

  delay(2500);
}

void aimServo(){
/*  int left = 0;
  int right = 15;

  int rand;
  rand = random(0,2);
  Serial.println(rand);
  
  if(rand == 0){
    aim.write(left);
    delay(1000);
  }
  else{
    aim.write(right);
    delay(1000);
  }

/*/  int direction = 0;
  int angle = 0;

while(direction == 0){
  angle = angle + 1;
  aim.write(angle);
  Serial.println(angle);
  delay(150);
  if(angle >= 15){
    direction = 1;
  }
}

while(direction == 1){
  angle = angle - 1;
  aim.write(angle);
  Serial.println(angle);
  delay(150);
  if(angle <= 0){
    direction = 0;
  }
}

}
