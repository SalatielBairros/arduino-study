#include <Servo.h>

const int SERVO_PORT = 9;
const int POTENCIOMETER = A5;
const int READING_DELAY = 100;

Servo servo_eng;

void setup() 
{
  servo_eng.attach(SERVO_PORT);
  pinMode(POTENCIOMETER, INPUT);
}

void loop() 
{
  int reading = analogRead(POTENCIOMETER);
  reading = map(reading, 0, 1023, 10, 170);
  servo_eng.write(reading);
  delay(READING_DELAY);
}
