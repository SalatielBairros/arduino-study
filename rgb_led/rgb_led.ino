const int LED_RED = 11;
const int LED_GREEN = 10;
const int LED_BLUE = 9;
const int BUTTON_RED = 7;
const int BUTTON_GREEN = 6;
const int BUTTON_BLUE = 5;
const int LED_MAX_INTENSITY = 255;
const int LED_OFF = 0;
const int READING_FREQUENCY = 100;

void setLedStatus(int led, int ledStatus);
void controllRGB();

void setup() {
  pinMode(LED_RED,OUTPUT);
  pinMode(LED_GREEN,OUTPUT);
  pinMode(LED_BLUE,OUTPUT);
  pinMode(BUTTON_RED,INPUT_PULLUP);
  pinMode(BUTTON_GREEN,INPUT_PULLUP);
  pinMode(BUTTON_BLUE,INPUT_PULLUP);
}

void loop() {
  controllRGB();
  delay(READING_FREQUENCY);
}

void controllRGB()
{
  int statusButtonRed = digitalRead(BUTTON_RED);
  int statusButtonGreen = digitalRead(BUTTON_GREEN);
  int statusButtonBlue = digitalRead(BUTTON_BLUE);

  setLedStatus(LED_RED, statusButtonRed);
  setLedStatus(LED_GREEN, statusButtonGreen);
  setLedStatus(LED_BLUE, statusButtonBlue);
}

void setLedStatus(int led, int ledStatus)
{
  if(ledStatus == LOW) {
    analogWrite(led, LED_MAX_INTENSITY);
  } 
  else {
    analogWrite(led, LED_OFF);
  }
}
