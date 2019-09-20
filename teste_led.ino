const int led = 12;
int blinkTime = 1000;

void setup() 
{
  // Colocamos o pino 12 do Arduino como OUTPUT (saída)
  pinMode(led, OUTPUT);
  attachInterrupt(0, buttonCall, RISING);
}

void loop() 
{
  blink(blinkTime);
}

void buttonCall(){  
 if(blinkTime == 1000){
  blinkTime = 250;
  return;
 }
 
 blinkTime = 1000;
}

void blink(int time){  
  digitalWrite(led, HIGH);  
  delay(time);
  
  digitalWrite(led, LOW);  
  delay(time);
}
