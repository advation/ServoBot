//Include the servo library.
#include <Servo.h>

//Assign servo objects
Servo rightServo;
Servo leftServo;

//Assign variable for LED
const int led = 13;

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

//Assign variables for range detection
//Objects within 25 centimetes will trigger the robot to do something. 
int distance = 25; 

//Random variable to be used for turning logic. 
int r = 0;

//Setup Loop
void setup()
{
  //Start Serial connection for troubleshooting.
  Serial.begin(9600); 
  
  //Assign pins to servo objects.
  rightServo.attach(6);
  leftServo.attach(5);

  //Set pin 8 as an output for the trigger to the sonic sensor.
  pinMode(trigger, OUTPUT);
  
  //Set pin 10 as an input for the echo from the sonic sensor. 
  pinMode(echo, INPUT);
  
  //Sets pin 13 as an ouput for an indicator light. 
  pinMode(led, OUTPUT);
}

//Main Loop
void loop()
{  
  //Do a ping, get the range, and assign a new range variable.
  int range = findRange();
  
  //Print the detected range to the serial port for troubleshooting. 
  //Serial.println(range);
  
  //Check the range value. If equal to 0 randomly generate a 1 or a 2 and assign that value to the r variable. 
  if(r == 0)
  {
    r = random(1,3);
  }

  //Avoidance Logic
  if(range <= distance)
  {
    //Stop, pivot, and run! Zombies!!!
    digitalWrite(led, HIGH);
    Serial.print("Avoid object: ");
    
    //Look at the r value and if it is equal to 1 go left or if it's equal to 2 go right. 
    if(r == 1)
    {
       left(); 
       Serial.println("Going Left!");
    }
    else if (r == 2)
    {
      right();
      Serial.println("Going Right!");
    }
  }
  else
  {
    //Toodaloo along, all is well.
    forward();
    Serial.println("Forward!");
    
    //Turns LED off.
    digitalWrite(13,LOW);
    
    //Reset the r variable to 0;
    r = 0;
  } 
  
    //Small delay to give the robot time to move.
    delay(75);
}

int findRange()
{
  // establish variables for duration of the ping, 
  // and the distance result in centimeters:
  long duration, cm;
  
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger, LOW);
  
  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  duration = pulseIn(echo, HIGH);
  
  //Calculate distance in centimeters
  cm = microsecondsToCentimeters(duration);
  
  //Returns the value of the range. 
  return cm;   
}

//This function does the math to calculate the distance of the object in centimeters
long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

//Moves the robot forward
void forward()
{
   rightServo.write(rightForward);
   leftServo.write(leftForward);
}

//Moves the robot backward
void backward()
{
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
