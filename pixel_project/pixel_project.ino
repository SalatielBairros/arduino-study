const int SERIAL_VEL = 9600;

const int LED_RED = 11;
const int LED_GREEN = 10;
const int LED_BLUE = 9;

const int BUTTON_RED = 7;
const int BUTTON_GREEN = 6;
const int BUTTON_BLUE = 5;
const int BUTTON_RESULT = 4;

const int POTENTIOMETER = A0;

const int LED_MAX_INTENSITY = 255;
const int LED_OFF = 0;
const int READING_FREQUENCY = 100;
const int MAX_POTENTIOMETER_READING = 1023;

int red, green, blue = 255;

void controllPixel();
void setLedColor(int led, int controllerButton, int *colorVariable);
void setResultVisualization();
void turnOnPixel();
bool isButtonBeingPressed(int button);
void monitoringVariables();

void setup() {
  pinMode(LED_RED,OUTPUT);
  pinMode(LED_GREEN,OUTPUT);
  pinMode(LED_BLUE,OUTPUT);
  pinMode(BUTTON_RED,INPUT_PULLUP);
  pinMode(BUTTON_GREEN,INPUT_PULLUP);
  pinMode(BUTTON_BLUE,INPUT_PULLUP);
  pinMode(BUTTON_RESULT,INPUT_PULLUP);
  pinMode(POTENTIOMETER, INPUT);
  Serial.begin(SERIAL_VEL);
}

void loop() {
  controllPixel();
  delay(READING_FREQUENCY);
}

void controllPixel()
{
  setLedColor(LED_RED, BUTTON_RED, &red);
  setLedColor(LED_GREEN, BUTTON_GREEN, &green);
  setLedColor(LED_BLUE, BUTTON_BLUE, &blue);

  setResultVisualization();
}

void setLedColor(int led, int controllerButton, int *colorVariable)
{
  if(isButtonBeingPressed(controllerButton)) {
    int potentiometerReading = analogRead(POTENTIOMETER);
    *colorVariable = map(potentiometerReading, 0, MAX_POTENTIOMETER_READING, 0, LED_MAX_INTENSITY); 
    analogWrite(led, *colorVariable);
  } 
  else {
    analogWrite(led, LED_OFF);
  }
}

void setResultVisualization()
{
  if(isButtonBeingPressed(BUTTON_RESULT)) {
    monitoringVariables();
    turnOnPixel();
  }
}

void turnOnPixel()
{
  analogWrite(LED_RED, red);
  analogWrite(LED_GREEN, green);
  analogWrite(LED_BLUE, blue);
}

bool isButtonBeingPressed(int button)
{
  int buttonStatus = digitalRead(button);
  return buttonStatus == LOW;
}

void monitoringVariables()
{
  Serial.print("RED: ");
  Serial.print(red);
  Serial.print("\t");
  Serial.print("GREEN: ");
  Serial.print(green);
  Serial.print("\t");
  Serial.print("BLUE: ");
  Serial.print(blue);
  Serial.println();
}
