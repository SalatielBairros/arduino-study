const int TRIG = 3;
const int ECHO = 2;
const int BUZZER = 7;
const int BUZZER_FREQUENCY = 1750;
const int SERIAL_VEL = 9600;
const int DISTANCE_FROM_ECHO_FACTOR = 58;
const int N_LEVELS = 6;

int warning_leds[N_LEVELS] = {8, 9, 10, 11, 12, 13};
int distance_levels[N_LEVELS] = {10, 20, 30, 40, 50, 60};
int buzzer_intervals[N_LEVELS] = {300, 250, 200, 150, 100, 0};

void setup() 
{
  Serial.begin(SERIAL_VEL);
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  pinMode(BUZZER,OUTPUT);

  configure_leds();
}

void configure_leds()
{
  for(int i = 0; i < N_LEVELS; i++)
  {
    pinMode(warning_leds[i],OUTPUT);
  }
}

void loop() 
{
  int distance = get_distance();
  print_distance(distance);
  int level = get_level(distance);
  set_warning_lights(level);
  set_buzzer(level);
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

void print_distance(int distance)
{
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");
}

void set_warning_lights(unsigned int level)
{
  for(int i = 0; i < N_LEVELS; i++)
  {
    int status = level > i ? HIGH : LOW;
    digitalWrite(warning_leds[i], status);
  }
}

int get_level(int distance)
{
  for(int i = 0; i < N_LEVELS; i++)
  {
    if(distance <= distance_levels[i])
    {
      return N_LEVELS - i;
    }
  }
  
  return 0;
}

void set_buzzer(int level)
{
  if(level < 1)
  {
    noTone(BUZZER);
    return;
  }

  if(level >= N_LEVELS)
  {
    tone(BUZZER, BUZZER_FREQUENCY);
    return;
  }

  interval = buzzer_intervals[level];
  tone(BUZZER,BUZZER_FREQUENCY);
  delay(interval);
  noTone(BUZZER);
  delay(interval);
}
