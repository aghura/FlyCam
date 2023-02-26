#include <Servo.h>

#define MAX 2000
#define MIN 1000
#define PIN1 9
#define PIN2 10

Servo Motor1;
Servo Motor2;

void setup() {

  Serial.begin(9600);

  Motor1.attach(PIN1, MIN, MAX);
  Motor2.attach(PIN2, MIN, MAX);
  
  Motor1.writeMicroseconds(MAX);
  Motor2.writeMicroseconds(MAX);

  while(Serial.available() == 0);{}
  Serial.read();

  Motor1.writeMicroseconds(MIN);
  Motor2.writeMicroseconds(MIN);
  delay(10);

  while(Serial.available() == 0);{}
  Serial.read();
}

void loop() {
  
  int MotorSpeed = 1200;
  Motor1.writeMicroseconds(MotorSpeed);
  Motor2.writeMicroseconds(MotorSpeed);

  if(Serial.available() == 1){
    Motor1.writeMicroseconds(MIN);
    Motor2.writeMicroseconds(MIN);
    exit(0);
  }
  
}
