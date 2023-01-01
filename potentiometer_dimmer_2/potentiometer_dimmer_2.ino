const int POTENTIOMETER = A0;
const int LED = 11;
const int MAX_POTENTIOMETER_READING = 1023;
const int MAX_PWM_OUTPUT = 255;
const int SERIAL_VEL = 9600;

void regulateLedIntensity(int potentiometerReading);
void printReading(int potentiometerReading);

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
  int pwm = map(potentiometerReading, 0, MAX_POTENTIOMETER_READING, 0, MAX_PWM_OUTPUT); 
  analogWrite(LED, pwm);
}

void printReading(int potentiometerReading)
{
  Serial.print("Reading: ");
  Serial.print(potentiometerReading);
  Serial.println();
}
