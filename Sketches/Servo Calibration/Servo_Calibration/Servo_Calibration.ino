#include <Servo.h>

Servo left;
Servo right;

void setup()
{
    left.attach(5);
    right.attach(6);
}

void loop()
{
  left.write(90);
  right.write(90);
  delay(500);
}
