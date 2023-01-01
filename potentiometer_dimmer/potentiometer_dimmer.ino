const int POTENTIOMETER = A0;
const int LED = 12;
const int MAX_PERIOD = 1023;
const int SERIAL_VEL = 9600;

void regulateLedIntensity(int potentiometerReading);
void setLedPWMSignal(int onPeriod, int offPeriod);
void printPWMIntervals(int onPeriod, int offPeriod);

void setup() {
  Serial.begin(SERIAL_VEL);
  pinMode(POTENTIOMETER, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  int potentiometerReading = analogRead(POTENTIOMETER);
  regulateLedIntensity(potentiometerReading);
}

void regulateLedIntensity(int potentiometerReading)
{
  int ledOnPeriod = potentiometerReading;
  int ledOffPeriod = MAX_PERIOD - ledOnPeriod;

  setLedPWMSignal(ledOnPeriod, ledOffPeriod);
  printPWMIntervals(ledOnPeriod, ledOffPeriod);
}

void setLedPWMSignal(int onPeriod, int offPeriod)
{
  if(onPeriod > 0){
    digitalWrite(LED, HIGH);
    delayMicroseconds(onPeriod);
  }

  if(offPeriod > 0){
    digitalWrite(LED, LOW);
    delayMicroseconds(offPeriod);
  }
}

void printPWMIntervals(int onPeriod, int offPeriod)
{
  Serial.print(onPeriod);
  Serial.print("\t");
  Serial.println(offPeriod);
}
