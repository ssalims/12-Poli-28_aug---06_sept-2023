//https://forum.arduino.cc/t/serial-available-and-serial-read-to-control-led/549280/8
//GolamMostafa oct18 post #8

char val;
#define led 2
bool flag1 = LOW;
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}
void loop()
{
  if (flag1 == HIGH)
  {
    //digitalWrite(PIN#, 1/0);
    digitalWrite(led, !digitalRead(led));
    delay(300);
  }
}
void serialEvent()
{
  val = Serial.read();
  if (val == '5')
  {
    flag1 = HIGH;
  }
  if(val != '5')
  {
    digitalWrite(led, LOW);
    flag1 = LOW;
  }
}