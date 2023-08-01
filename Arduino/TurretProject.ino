#include <Servo.h>

#define STEPPER_PIN_1 9
#define STEPPER_PIN_2 10
#define STEPPER_PIN_3 11
#define STEPPER_PIN_4 12

int num;
Servo servo;
int deg = 90;

void OneStep(bool dir, char speed);

void setup() 
{
  Serial.begin(9600);
  servo.attach(8);
  servo.write(90);
  pinMode(STEPPER_PIN_1, OUTPUT);
  pinMode(STEPPER_PIN_2, OUTPUT);
  pinMode(STEPPER_PIN_3, OUTPUT);
  pinMode(STEPPER_PIN_4, OUTPUT);
}

void loop() 
{
  if(Serial.available())
  {
    num = Serial.read() - 48;
    switch(num)
    {
      case 1:
      {
        OneStep(false,'f');
        break;
      }
      case 2:
      {
        OneStep(false,'s');
        break;
      }
      case 3:
      {
        OneStep(true,'f');
        break;
      }
      case 4:
      {
        OneStep(true,'s');
        break;
      }
      case 5:
      {
        if(deg < 180)
        {
          deg+=2;
          servo.write(deg);
        }
        break;
      }
      case 6:
      {
        if(deg > 0)
        {
          deg-=2;
          servo.write(deg);
        }
        break;
      }
    }
  }
}


void OneStep(bool dir, char speed)
{
  int end = (speed == 'f')? end=12 : end=4;
  if(dir)
  {
    for(int i =0; i < end; i++)
    {
      digitalWrite(STEPPER_PIN_1, HIGH);
      digitalWrite(STEPPER_PIN_2, LOW);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, LOW);
      delay(2);
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, HIGH);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, LOW);
      delay(2);
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, LOW);
      digitalWrite(STEPPER_PIN_3, HIGH);
      digitalWrite(STEPPER_PIN_4, LOW);
      delay(2);
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, LOW);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, HIGH);
      delay(2);
    }
  }
  else
  {
    for(int i =0; i < end; i++)
    {
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, LOW);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, HIGH);
      delay(2);
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, LOW);
      digitalWrite(STEPPER_PIN_3, HIGH);
      digitalWrite(STEPPER_PIN_4, LOW);
      delay(2);
      digitalWrite(STEPPER_PIN_1, LOW);
      digitalWrite(STEPPER_PIN_2, HIGH);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, LOW);
      delay(2);
      digitalWrite(STEPPER_PIN_1, HIGH);
      digitalWrite(STEPPER_PIN_2, LOW);
      digitalWrite(STEPPER_PIN_3, LOW);
      digitalWrite(STEPPER_PIN_4, LOW);
      delay(2);
    }
  } 
}
