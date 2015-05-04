#include <Servo.h>

Servo rightServo;
Servo leftServo;

const int rightForward = 0; 
const int rightBackward = 180;

const int leftForward = 180;
const int leftBackward = 0; 

const int brake = 90;

const int irSensor = 0;

int range = 15;

void setup()
{
	Serial.begin(9600);
	rightServo.attach(6);
	leftServo.attach(5);
}

void loop()
{
///////////////////// NEW CODE /////////////////////////
	
	if(getRange() >= range)
	{
		right();
	}
	else
	{
		forward();
	}
	delay(100);

/////////////////////////////////////////////////////////
}

int getRange()
{
  int sensorValue = analogRead(irSensor);

  float distance = 5262.1/sensorValue;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  return distance;
}

void forward()
{	
	rightServo.write(rightForward);
	leftServo.write(leftForward);
}

void backward()
{
	rightServo.write(rightBackward);
	leftServo.write(leftBackward);
}

void left()
{
	rightServo.write(rightForward);
	leftServo.write(leftBackward);
}

void right()
{
	rightServo.write(rightBackward);
	leftServo.write(leftForward);
}

void allStop()
{
	rightServo.write(brake);
	leftServo.write(brake);
}
