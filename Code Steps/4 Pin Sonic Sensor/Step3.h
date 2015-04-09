#include <Servo.h>

Servo rightServo;
Servo leftServo;

const int rightForward = 0; 
const int rightBackward = 180;

const int leftForward = 180;
const int leftBackward = 0; 

const int brake = 90;

void setup()
{
///////////////////// NEW CODE /////////////////////////

	rightServo.attach(6);
	leftServo.attach(5);

////////////////////////////////////////////////////////

void loop()
{
///////////////////// NEW CODE /////////////////////////

	forward();

////////////////////////////////////////////////////////
}

void forward()
{	
	rightServo.write(rightForward);
	leftServo.write(leftForward);
}