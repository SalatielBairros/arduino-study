const int POTENTIOMETER = A0;
const int SERIAL_VEL = 9600;
const float VOLTS = 5.0;
const int READING_INTERVAL = 100;

void getTensionFromReading();
void printTension();

void setup() {
  Serial.begin(SERIAL_VEL);
  pinMode(POTENTIOMETER, INPUT);
}

void loop() {
  int currentReading = analogRead(POTENTIOMETER);
  float tension = getTensionFromReading(currentReading);
  
  printTension(tension);
  
  delay(READING_INTERVAL);
}

float getTensionFromReading(int currentReading)
{
  return currentReading * VOLTS / 1024.0;
}

void printTension(float tension)
{
  Serial.print("Tension: ");
  Serial.print(tension);
  Serial.println();
}
