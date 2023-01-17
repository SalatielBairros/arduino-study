const int LED_A = 12; 
const int LED_B = 11; 
const int LED_C = 10; 
const int LED_D = 9; 
const int LED_E = 8; 
const int LED_F = 7; 
const int LED_G = 6; 
const int LED_DOT = 5;
const int N_NUMBERS = 10;
const int N_LEDS = 8;
const int INTERVAL = 1000;
const int SERIAL_VEL = 9600;

void setDisplayInput(int* input);
void listAllNumbers();

void setup() {
  Serial.begin(SERIAL_VEL);
  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_C, OUTPUT);
  pinMode(LED_D, OUTPUT);
  pinMode(LED_E, OUTPUT);
  pinMode(LED_F, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_DOT, OUTPUT);
}

void loop() {
  listAllNumbers();
}

void listAllNumbers()
{
    int numbers[N_NUMBERS][N_LEDS] = {
    {1,1,1,1,1,1,0,0}, // 0
    {0,1,1,0,0,0,0,0}, // 1
    {1,1,0,1,1,0,1,0}, // 2
    {1,1,1,1,0,0,1,0}, // 3
    {0,1,1,0,0,1,1,0}, // 4
    {1,0,1,1,0,1,1,0}, // 5
    {0,0,1,1,1,1,1,1}, // 6
    {1,1,1,0,0,0,0,0}, // 7
    {1,1,1,1,1,1,1,0}, // 8
    {1,1,1,0,0,1,1,1}, // 9    
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
  int inputIndex = 0;
  for(int segment = LED_A; segment >= LED_DOT; segment--)
  {    
    int value = input[inputIndex];
    digitalWrite(segment, value);
    inputIndex++;
  }
}
