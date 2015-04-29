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
	rightServo.attach(6);
	leftServo.attach(5);
}

void loop()
{
///////////////////// NEW CODE /////////////////////////

	forward();
	delay(2000);

	backward();
	delay(2000);

	left()
	delay(2000);

	right();
	delay(2000);

	allStop();
	delay(2000);

/////////////////////////////////////////////////////////
}

void forward()
{	
	rightServo.write(rightForward);
	leftServo.write(leftForward);
}

///////////////////// NEW CODE /////////////////////////

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

/////////////////////////////////////////////////////////