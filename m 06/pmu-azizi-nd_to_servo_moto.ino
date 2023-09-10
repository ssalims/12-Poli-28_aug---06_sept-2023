#include <ESP32Servo.h>
const int servoPin = 21;           //pin 21
Servo Myservo;

void setup()
{
  pinMode(2, OUTPUT);
  Serial.begin(115200);
  Myservo.attach(servoPin);
  Myservo.write(0);

  while (!Serial);
  Serial.println("Node-Red to Servo moto..");
}

void loop() {
  if (Serial.available())
  {
  int state = Serial.parseInt();
     Myservo.write(state);
     Serial.print("Servo moto rotate ");
     Serial.println(state);
    }
}