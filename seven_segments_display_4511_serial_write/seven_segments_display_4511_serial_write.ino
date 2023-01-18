const int PIN_A = 12; 
const int PIN_B = 9; 
const int PIN_C = 10; 
const int PIN_D = 11; 
const int N_NUMBERS = 10;
const int N_BITS = 4;
const int SERIAL_VEL = 9600;

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
void displayInformedNumber();
bool hasByteOnSerialPort();
bool isValidDigit(int serialReading);

void setup() {  
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_D, OUTPUT);

  Serial.begin(SERIAL_VEL);
  Serial.println("Inform a number between 0 and 9:");
}

void loop() {
  if(hasByteOnSerialPort()){
    displayInformedNumber();  
  }  
}

void displayInformedNumber()
{
  int serialNumber = getSerialNumber();
  if(isValidDigit(serialNumber))
  {    
    setDisplayInput(numbers[serialNumber]);
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

int getSerialNumber()
{
  char serialReading = Serial.read();
  serialReading = serialReading - 48;
  return serialReading;
}

bool hasByteOnSerialPort()
{
  return Serial.available() > 0;
}

bool isValidDigit(int serialReading)
{
  return serialReading >= 0 && serialReading <= 9;
}
