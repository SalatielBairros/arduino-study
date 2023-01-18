const int PIN_A = 12; 
const int PIN_B = 9; 
const int PIN_C = 10; 
const int PIN_D = 11; 
const int BUTTON = 2;
const int N_NUMBERS = 10;
const int N_BITS = 4;
const int SERIAL_VEL = 9600;
const int DELAY_INTERVAL = 150;

int pinSequence[N_BITS] = {PIN_A, PIN_B, PIN_C, PIN_D};
int numbers[N_NUMBERS][N_BITS] = {
      {0,0,0,0}, // 0
      {0,0,0,1}, // 1
      {0,0,1,0}, // 2
      {0,0,1,1}, // 3
      {0,1,0,0}, // 4
      {0,1,0,1}, // 5
      {0,1,1,0}, // 6
      {0,1,1,1}, // 7
      {1,0,0,0}, // 8
      {1,0,0,1}, // 9    
    };

void setDisplayInput(int* input);
void displayRandomNumber();
int getRandomNumber();
bool isButtonBeingPressed();

void setup() {  
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_D, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP); 

  Serial.begin(SERIAL_VEL);  
}

void loop() {
  if(isButtonBeingPressed()){
    delay(DELAY_INTERVAL);
    displayRandomNumber();  
  }  
}

void displayRandomNumber()
{
  int number = getRandomNumber();
  setDisplayInput(numbers[number]);  
}

void setDisplayInput(int* input)
{  
  for(int pinIndex = 0; pinIndex < N_BITS; pinIndex++)
  {    
    int value = input[pinIndex];
    int pin = pinSequence[N_BITS - (pinIndex + 1)];
    digitalWrite(pin, value);    
  }
}

int getRandomNumber()
{  
  return random(1, 10);
}

bool isButtonBeingPressed()
{
  return digitalRead(BUTTON) == LOW;
}
