const int TRIG = 3;
const int ECHO = 2;
const int MAX_DISTANCE = 500;
const int SERIAL_VEL = 9600;
const int DISTANCE_FROM_ECHO_FACTOR = 58;
const int SENSOR_DELAY = 100;

void setup() 
{
  Serial.begin(SERIAL_VEL);
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
}

void loop() 
{
  int distance = get_distance();
  if(distance <= MAX_DISTANCE)
  {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println("cm");
  }
  
  delay(SENSOR_DELAY);
}

int get_distance()
{
  trigger_sensor();
  return get_echo_distance();  
}

void trigger_sensor()
{
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
}

int get_echo_distance()
{
  return pulseIn(ECHO, HIGH) / DISTANCE_FROM_ECHO_FACTOR;
}
