/*
  ServoBot IR Distance Sensor Test
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

 This example code is in the public domain.
 */

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.print("Sensor value: ");
  Serial.print(sensorValue);
  Serial.println(" bits");
 
  
  // calculate the distance in centimeters
  float distance = 5262.1/sensorValue; 
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  Serial.println(" " );
  Serial.println(" " );
  
  
  delay(500);        // delay in between reads for stability
}
