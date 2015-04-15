const int irSensor = A0; 

//Lower = farther away
//Higher = closer
const int target = 250;

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
  delay(100);
}

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
