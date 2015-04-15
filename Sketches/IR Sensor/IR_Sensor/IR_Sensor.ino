const int irSensor = A0; 
int distance = 0; 

//Lower = farther away
//Higher = closer
const int target = 150;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if(range() >= target)
  {
     Serial.println("Turn"); 
  }
  else
  {
    Serial.println("Forward");
  }
}

int range()
{
  //Sensor Smoothing
  for(int i=0;i<=4;i++)
  {
    distance = analogRead(irSensor);
    delay(10);
    distance = distance + distance;
  }
  
  distance = distance / 4;

  return distance;
}
