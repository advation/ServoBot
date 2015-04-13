const int irSensor = A0; 
int distance = 0; 

void setup()
{
  Serial.begin(9600);
}

void loop()
{
   distance = analogRead(irSensor);
   Serial.println(distance, DEC);
   delay(50);
}
