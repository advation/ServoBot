//Include the servo library.
#include <Servo.h>

//Assign servo objects
Servo rightServo;
Servo leftServo;

//Assign variables for sonic sensor
const int trigger = 8;
const int echo = 10;

//Assign variables for servo directions
//Max is 180 and turns the servo one direction. 
//Min is 0 and turns the servo the other direction. 
//Middle is 90 and prevents the servo from moving in either direction.
//The following assignments can be adjusted to trim the servo. 
const int rightForward = 0; 
const int rightBackward = 180;

const int leftForward = 180;
const int leftBackward = 0; 

const int brake = 90;

//Assign varibles to count the number of revolutions.
int revolutions = 0; 

//Light sensor variables
int ldr = 0;
int ldrValue = 0; 
int lightSensitivity = 25;

//Assign variables for range detection
//Objects within 10 centimetes will trigger the robot to do something. 
int distance = 15; 

int r = 0;

//Setup Loop
void setup()
{
  //Start Serial connection for troubleshooting.
  Serial.begin(9600); 
  
  //Assign pins to servo objects.
  rightServo.attach(6);
  leftServo.attach(5);

  //Sets pin 13 as an ouput for an indicator light. 
  pinMode(13, OUTPUT);
}

//Main Loop
void loop()
{  
  //Do a ping, get the range, and assign a new range variable.
  int range = findRange();
  
  //Print the detected range to the serial port for troubleshooting. 
  //Serial.println(range);
  
  if(r == 0)
  {
    r = random(1,3);
  }

  //Avoidance Logic
  if(range <= distance)
  {
    //Stop, pivot, and run! Zombies!!!
    digitalWrite(13, HIGH);
    //Serial.println("Avoid object!!");
    //allStop();
    //delay(250);
    
    if(r == 1)
    {
       left(); 
       Serial.println("left");
    }
    else if (r == 2)
    {
      right();
      Serial.println("right");
    }

    delay(100);
  }
  else
  {
    //Toodaloo along, all is well.
    digitalWrite(13,LOW);
    //Serial.println("Forward!");
    forward();
    r = 0;
    Serial.println(' ');
  } 
  
  //Serial.print("Total Revolutions");
  //Serial.println(revolutions);
}

int findRange()
{
  // establish variables for duration of the ping, 
  // and the distance result in centimeters:
  long duration, cm;
  
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trigger, OUTPUT);
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger, LOW);
  
  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echo, INPUT);
  duration = pulseIn(echo, HIGH);
  
  //Calculate distance in centimeters
  cm = msToCm(duration);
  
  //Returns the value of the range. 
  return cm;   
}

//This function does the math to calculate the distance of the object in centimeters
long msToCm(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

//Moves the robot forward
void forward()
{
   if(lightSensor())
   {
     plusCount();
   }
   rightServo.write(rightForward);
   leftServo.write(leftForward);
}

//Moves the robot backward
void backward()
{
  if(lightSensor())
   {
     minusCount();
   }
   rightServo.write(rightBackward);
   leftServo.write(leftBackward);
}

//Pivots the robot to the left
void left()
{
   rightServo.write(rightForward);
   leftServo.write(leftBackward);
}

//Pivots the robot to the right
void right()
{
   rightServo.write(rightBackward);
   leftServo.write(leftForward);
}

//Stops the robot. 
void allStop()
{
   rightServo.write(brake);
   leftServo.write(brake);
}

//Adds one to the revolution count.
int plusCount()
{
  return revolutions++;
}

//Subtracts one from the revolution count. 
int minusCount()
{
  return revolutions--;
}

int lightSensor()
{
   //Analog read for ldr pin.
   ldrValue = analogRead(ldr);
   //Serial.println(ldrValue);
   
   //Logic
   if(ldrValue <= lightSensitivity)
   {
     return true;
   }
   else
   {
     return false;
   }
}

