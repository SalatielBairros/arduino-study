const int BUZZER = 10;
const int INITIAL_FREQUENCY = 440;
const int BEEP_DURATION = 400;
const int UP_BUTTON = 11;
const int DOWN_BUTTON = 9;
const int FREQUENCY_STEP = 100;
const int SERIAL_PORT = 9600;

int currentFrequency = INITIAL_FREQUENCY;

bool isButtonActive(int button);
void beep(int frequency);
void printCurrentFrequency(bool up);

void setup() {
  pinMode(BUZZER, OUTPUT);
  pinMode(UP_BUTTON, INPUT_PULLUP);
  pinMode(DOWN_BUTTON, INPUT_PULLUP);
  Serial.begin(SERIAL_PORT);
}

void loop() {
  if(isButtonActive(UP_BUTTON))
  {
    currentFrequency += FREQUENCY_STEP;
    beep(currentFrequency);
    printCurrentFrequency(true);
  }
  else if(isButtonActive(DOWN_BUTTON) && currentFrequency > FREQUENCY_STEP)
  {
    currentFrequency -= FREQUENCY_STEP;
    beep(currentFrequency);
    printCurrentFrequency(false);
  }
}

bool isButtonActive(int button)
{
  return digitalRead(button) == LOW;
}

void beep(int frequency)
{
  tone(BUZZER, frequency);
  delay(BEEP_DURATION);
  noTone(BUZZER);
}

void printCurrentFrequency(bool up)
{
  if(up){
    Serial.print("Up Frequency to: ");
  }
  else{
    Serial.print("Down Frequency to: ");
  }
  Serial.print(currentFrequency);
  Serial.println();  
}
