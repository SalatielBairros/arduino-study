const int LIGHT_SENSOR = A0;
const int LED = 7;
const int SERIAL_PORT = 9600;
const int MIN_LIGHT_TENSION = 600;
const int READING_INTERVAL = 200;

int currentReading = 0;
float tension = 0.0;

void printCurrentReading();
float getTension();
void printTension();
void controllLed();

void setup() {
  pinMode(LIGHT_SENSOR, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(SERIAL_PORT);
}

void loop() {
  currentReading = analogRead(LIGHT_SENSOR);
  tension = getTension();
  
  printCurrentReading();
  printTension();

  controllLed();
  
  delay(READING_INTERVAL);
}

void printCurrentReading()
{
  Serial.print("Reading: ");
  Serial.print(currentReading);
  Serial.print("\t");
}

float getTension()
{
  return currentReading * 5.0 / 1024.0;
}

void printTension()
{
  Serial.print("Tension: ");
  Serial.print(tension);
  Serial.print("V");
  Serial.println();
}

void controllLed()
{
  if(currentReading < MIN_LIGHT_TENSION)
  {
    digitalWrite(LED, HIGH);
  }
  else
  {
    digitalWrite(LED, LOW);
  }
}
