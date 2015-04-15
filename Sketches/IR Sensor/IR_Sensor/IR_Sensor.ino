//Include the servo library
#include <Servo.h>

//Assign servo objects
Servo rightServo;
Servo leftServo;

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

//Assign variable for LED
const int led = 3;

//Assign variable for IR sensor
const int irSensor = A0; 

//Assign variables for range detections.
/*
The lower the number the farther away the object is.
The higher the number the closer the object is. 
*/
const int target = 250;

void setup()
{
  //Start Serial connection for troubleshooting
  Serial.begin(9600);
  
  //Assign pins to servo objects
  rightServo.attach(6);
  leftServo.attach(5);
  
  //Sets LED pin as an output for an indicator light.
  pinMode(led, OUTPUT);
}

void loop()
{
  //Avoidance logic
  /*
  Check the returned value of range() and compare it to the target variable.
  */
  if(range() >= target)
  {
     digitalWrite(led, HIGH);
     right();
  }
  else
  {
    digitalWrite(led, LOW);
    forward();
  }
  delay(100);
}

//Uses the IR sensor and returns a value representing the range of the object. 
int range()
{
  int distance[3];
  int average = 0;
  
  //Sensor Smoothing
  for(int i=0;i<=2;i++)
  {
      distance[i] = analogRead(irSensor);
      delay(10);
  }
  
  //Calculate the average
  for(int a=0;a<=2;a++)
  {
     average = average + distance[a];   
  }
  
  average = average / 3;
  
  return average;
}

void forward()
{
  rightServo.write(rightForward);
  leftServo.write(leftForward);
  Serial.println("Forward");
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