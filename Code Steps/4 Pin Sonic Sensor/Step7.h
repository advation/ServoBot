#include <Servo.h>

Servo rightServo;
Servo leftServo;

const int rightForward = 0; 
const int rightBackward = 180;

const int leftForward = 180;
const int leftBackward = 0; 

const int brake = 90;

const int trigger = 8;
const init echo = 10;

const int trigger = 8;
const init echo = 10;

int range = 15;

void setup()
{
	rightServo.attach(6);
	leftServo.attach(5);
}

void loop()
{
///////////////////// NEW CODE /////////////////////////
	int range = findRange(); 

	if(range <= distance)
	{
		left();
	}
	else
	{
		forward();
	}
	
	delay(100);
/////////////////////////////////////////////////////////
}

int findRange()
{
	long duration, cm;

	pinMode(trigger, OUTPUT);

	digitalWrite(trigger, LOW);
	delayMicroseconds(2);

	digitalWrite(trigger, HIGH);
	delayMicroseconds(4);
	digitalWrite(trigger, LOW);

	pinMode(echo, INPUT);
	duration = pulseIn(echo, HIGH);

	cm = msToCm(duration);
}

long msToCm(long microseconds)
{
	return microseconds / 29 / 2;
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