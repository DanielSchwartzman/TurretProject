#include <Servo.h>

int serialInput;
Servo horizontalServo;
Servo verticalServo;
int horizontalDeg = 90;
int verticalDeg = 90;

void setup() 
{
  Serial.begin(9600);
  
  horizontalServo.attach(8); //Depends on the pin you chose to connect the servo to
  horizontalServo.write(horizontalDeg);
  
  verticalServo.attach(9); //Depends on the pin you chose to connect the servo to
  verticalServo.write(verticalDeg);
}

void loop() 
{
  if(Serial.available())
  {
    serialInput = Serial.read() - 48;
    switch(serialInput)
    {
      case 1:
      {
         horizontalDeg += 4;
         horizontalServo.write(horizontalDeg);
        break;
      }
      case 2:
      {
         horizontalDeg += 2;
         horizontalServo.write(horizontalDeg);
        break;
      }
      case 3:
      {
         horizontalDeg -= 4;
         horizontalServo.write(horizontalDeg);
        break;
      }
      case 4:
      {
         horizontalDeg -= 2;
         horizontalServo.write(horizontalDeg);
        break;
      }
      case 5:
      {
        if(deg < 180)
        {
          verticalDeg += 2;
          verticalServo.write(verticalDeg);
        }
        break;
      }
      case 6:
      {
        if(deg > 0)
        {
          verticalDeg -= 2;
          verticalServo.write(verticalDeg);
        }
        break;
      }
    }
  }
}
