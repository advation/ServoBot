//Include the servo library
#include <Servo.h>

//Assign servo objects
Servo rightServo;
Servo leftServo;
Servo eyes;

//Assign variables for servo directions
/*
Max is 180 and rotates the servo in one direction.
Min is 0 and rotates the servo in the opposite direction. 
Middle is 90 and stops the servo from moving.
*/
const int rightForward = 0;
const int rightBackward = 180;

const int leftForward = 180;
const int leftBackward = 0; 

const int brake = 90;

const int eyesLeft = 120;
const int eyesRight = 40;
const int eyesForward = 85;

//Assign variable for IR sensor
const int irSensor = 0;

//Distance on either side of the robot
int leftDistance, rightDistance;

//Assign variables for range detections.
const int range = 15;

void setup()
{
  //Start Serial connection for troubleshooting
  Serial.begin(9600);
  
  //Assign pins to servo objects
  rightServo.attach(6);
  leftServo.attach(5);
  
  eyes.attach(8);
  eyes.write(eyesForward);
}

void loop()
{
  //Avoidance logic
  /*
  Check the returned value of range() and compare it to the target variable.
  */
  if(getRange() >= range)
  {  
     //Move forard
     forward();
  }
  else
  {
     //Stop ServoBot
     allStop();
     delay(100);
     
     //Turn left for a little
     lookLeft();
     
     //Check left distance
     leftDistance = getRange();
     delay(100);
     
     //Turn right for a little
     lookRight();
    
     //Check right distance
     rightDistance = getRange();
     delay(100);
     
     eyes.write(eyesForward);
     delay(100);
     
     //Compare the 2 distances
     compareDistance();
  }
  delay(10);
}

void compareDistance()
{
  if(leftDistance > rightDistance)
  {
      Serial.println("Going left!");
      left();
      delay(300);
  }
  else if(rightDistance > leftDistance)
  {
     Serial.println("Going right!");
     right();
     delay(300);
  }
  else
  {
     //turn 180 degrees
     backwards();
     delay(250);
     left();
     delay(1000);
  }
}

//Uses the IR sensor and returns a value representing the range of the object. 
int getRange()
{
  //Read the input on analog pin 0
  int sensorValue = analogRead(irSensor);

  //Calculate the distance in centimeters
  float distance = 5262.1/sensorValue;

  //Print the calculated distance.
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  return distance;
}

void lookLeft()
{
   eyes.write(eyesLeft);
   delay(500);
}

void lookRight()
{
   eyes.write(eyesRight);
   delay(500);
}

void forward()
{
  rightServo.write(rightForward);
  leftServo.write(leftForward);
  Serial.println("Forward");
}

void backwards()
{
  rightServo.write(rightBackward);
  leftServo.write(leftBackward);
  Serial.println("Backward");
}

void left()
{
  rightServo.write(rightForward);
  leftServo.write(leftBackward);
  Serial.println("Left");
}

void right()
{
  rightServo.write(rightBackward);
  leftServo.write(leftForward);
  Serial.println("Right");
}

void allStop()
{
   rightServo.write(brake); 
   leftServo.write(brake);
   Serial.println("Stop");
}
