const int LIGHT_SENSOR = A0;
const int SERIAL_VEL = 9600;
const int MIN_LIGHT_TO_OBSTACLE = 700;
const int READING_INTERVAL = 500;

int currentReading = 0;

void printReading();
bool hasObstacle();
void printObstacle();

void setup() {
  Serial.begin(SERIAL_VEL);
  pinMode(LIGHT_SENSOR, INPUT);
}

void loop() {
  currentReading = analogRead(LIGHT_SENSOR);
  printReading();

  bool obstacle = hasObstacle();

  if(obstacle){
    printObstacle();
  }
  
  Serial.println();

  delay(READING_INTERVAL);
}

void printReading()
{
  Serial.print("Reading: ");
  Serial.print(currentReading);
  Serial.print("\t"); 
}

bool hasObstacle()
{
  return currentReading <= MIN_LIGHT_TO_OBSTACLE;
}
 
void printObstacle()
{
  Serial.print("Obstacle: Yes");
}
