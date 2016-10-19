//seth berryhill
//oct 13, 2016
//proto1 code for me223 group project

// code will connect 2 motors constantly spinning at the same speed, controlled with pot
// and also 2 servos used as a gate to feed out ping pong balls

#include <Servo.h>

int motor1 = 4;
int motor2 = 6;
int servo1Pin = 8;
int servo2Pin = 10;

int potPin = 0;
int motorValue;

Servo servo1;
Servo servo2;


void setup(){
 pinMode(motor1, OUTPUT);
 pinMode(motor2, OUTPUT);

 servo1.attach(servo1Pin);
 servo2.attach(servo2Pin);
}


void loop(){
 spinMotors();
 servoGate();
}


void spinMotors(){
  //reads a pot and writes that speed to both motors

 motorValue = analogRead(potPin);

 digitalWrite(motor1, motorValue);
 digitalWrite(motor2, motorValue);
}


void servoGate(){
  //opens and closes servo1, waits 5 seconds, then opens and closes servo2

  int closed = 0;
  int open = 90;

  servo1.write(closed);
  servo2.write(closed);

  servo1.write(open);
  delay(250);
  servo1.write(closed);

  delay(5000);

  servo2.write(open);
  delay(250);
  servo2.write(closed);
}
