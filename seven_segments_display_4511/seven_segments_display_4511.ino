const int PIN_A = 12; 
const int PIN_B = 9; 
const int PIN_C = 10; 
const int PIN_D = 11; 
const int N_NUMBERS = 10;
const int N_BITS = 4;
const int INTERVAL = 1000;
const int SERIAL_VEL = 9600;

int pinSequence[N_BITS] = {PIN_A, PIN_B, PIN_C, PIN_D};

void setDisplayInput(int* input);
void listAllNumbers();

void setup() {
  Serial.begin(SERIAL_VEL);
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_D, OUTPUT);
}

void loop() {
  listAllNumbers();
}

void listAllNumbers()
{
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

  for(int n = 0; n < N_NUMBERS; n++)
  {
    Serial.print("listing number:");
    Serial.print(n);
    Serial.println();
    setDisplayInput(numbers[n]);
    delay(INTERVAL);
  }
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
