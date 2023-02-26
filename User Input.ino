#include <Servo.h>

#define MAX 2000
#define MIN 1000
#define PIN1 9
#define PIN2 10

Servo Motor1;
Servo Motor2;

void setup() {
  Serial.begin(9600);
  Serial.println("Calibrating now. Motor may start");

  Motor1.attach(PIN1, MIN, MAX);
  Motor2.attach(PIN2, MIN, MAX);

  Serial.println("Sending Maximum to Both Motors: 2000");
  Motor1.writeMicroseconds(MAX);
  Motor2.writeMicroseconds(MAX);
  Serial.println("Wait two seconds and enter any key.");

  while(Serial.available() == 0);{}
  Serial.read();

  Serial.println("Sending Minimum to Both Motors: 1000");
  Motor1.writeMicroseconds(MIN);
  Motor2.writeMicroseconds(MIN);
  Serial.println("Calibration done. Wait two seconds and enter speed.");
}

void loop() {
  while(Serial.available() == 0);{}
  int MotorNumber = Serial.read();
  
  if(MotorNumber == 'a'){
    int Motor1Speed = Serial.parseInt();
    if (Motor1Speed >= MIN && Motor1Speed <= MAX){
      Motor1.writeMicroseconds(Motor1Speed);
      double Motor1Percent = (Motor1Speed - 1000)/10;
      Serial.print("Motor1 Speed at: ");
      Serial.print(Motor1Percent);
      Serial.println("%");
    }
    else{
      Serial.println("Enter Speed in Given Range");
    } 
  }
  
  if(MotorNumber == 'b'){
    int Motor2Speed = Serial.parseInt();
    if (Motor2Speed >= MIN && Motor2Speed <= MAX){
      Motor2.writeMicroseconds(Motor2Speed);
      double Motor2Percent = (Motor2Speed - 1000)/10;
      Serial.print("Motor2 Speed at: ");
      Serial.print(Motor2Percent);
      Serial.println("%");
    }
    else{
      Serial.println("Enter Speed in Given Range");
    } 
  }

  if(MotorNumber == 'c'){
    int MotorSpeed = Serial.parseInt();
    if (MotorSpeed >= MIN && MotorSpeed <= MAX){
      Motor1.writeMicroseconds(MotorSpeed);
      Motor2.writeMicroseconds(MotorSpeed);
      double MotorPercent = (MotorSpeed - 1000)/10;
      Serial.print("Motor Speed at: ");
      Serial.print(MotorPercent);
      Serial.println("%");
    }
    else{
      Serial.println("Enter Speed in Given Range");
    } 
  }

  else{
    Serial.println("No no no no!");
  }
  
}
