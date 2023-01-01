const int BUZZER = 10;
const int BEEP_DURATION = 400;
const int UP_BUTTON = 11;
const int DOWN_BUTTON = 9;
const int SERIAL_PORT = 9600;
const int MAX_NOTES_INDEX = 6;

const int C = 261;
const int D = 293;
const int E = 329;
const int F = 349;
const int G = 391;
const int A = 440;
const int B = 493;

int octave[7] = {C, D, E, F, G, A, B};

int currentNoteIndex = 0;
int currentFrequency = octave[currentNoteIndex];

bool isButtonActive(int button);
void beep(int frequency);
void printCurrentFrequency(bool up);
int getCurrentFrequency();
void increaseNote();
void decreaseNote();

void setup() {
  pinMode(BUZZER, OUTPUT);
  pinMode(UP_BUTTON, INPUT_PULLUP);
  pinMode(DOWN_BUTTON, INPUT_PULLUP);
  Serial.begin(SERIAL_PORT);
}

void loop() {
  if(isButtonActive(UP_BUTTON))
  {
    increaseNote();    
    beep();
    printCurrentFrequency();
  }
  else if(isButtonActive(DOWN_BUTTON))
  {
    decreaseNote();
    beep();
    printCurrentFrequency();
  }
}

void increaseNote()
{
  if(currentNoteIndex < MAX_NOTES_INDEX)
  {
    currentNoteIndex += 1;
  }
}

void decreaseNote()
{
  if(currentNoteIndex > 0)
  {
    currentNoteIndex -= 1;
  }
}

bool isButtonActive(int button)
{
  return digitalRead(button) == LOW;
}

void beep()
{
  tone(BUZZER, getCurrentFrequency());
  delay(BEEP_DURATION);
  noTone(BUZZER);
}

int getCurrentFrequency()
{
  return octave[currentNoteIndex];
}

void printCurrentFrequency()
{
  Serial.print("Current Frequency is: ");
  Serial.print(currentFrequency);
  Serial.println();  
}
