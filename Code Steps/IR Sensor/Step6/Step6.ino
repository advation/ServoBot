#include <Servo.h>

Servo rightServo;
Servo leftServo;

const int rightForward = 0; 
const int rightBackward = 180;

const int leftForward = 180;
const int leftBackward = 0; 

const int brake = 90;

///////////////////// NEW CODE /////////////////////////
const int irSensor = 0;

int range = 15;
////////////////////////////////////////////////////////

void setup()
{
///////////////////// NEW CODE /////////////////////////
	Serial.begin(9600);
////////////////////////////////////////////////////////
	rightServo.attach(6);
	leftServo.attach(5);
}

void loop()
{
	forward();
	delay(2000);

	backward();
	delay(2000);

	left();
	delay(2000);

	right();
	delay(2000);

	allStop();
	delay(2000);
}

///////////////////// NEW CODE /////////////////////////
int getRange()
{
  int sensorValue = analogRead(irSensor);

  float distance = 5262.1/sensorValue;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  return distance;
}
/////////////////////////////////////////////////////////

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
