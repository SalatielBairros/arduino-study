#include <Servo.h>

const int SERVO_PORT = 9;

// The minimum angle is 10 and not 0 because of phisical and hardware limitation. It's the same thing for the max angle, that is 170, not 180.
const int SERVO_START_ANGLE = 10;

Servo servo_eng;

void setup() 
{
  servo_eng.attach(SERVO_PORT);
  servo_eng.write(SERVO_START_ANGLE);
}

void loop() 
{
  servo_eng.write(10);
  delay(5000);
  servo_eng.write(120);
  delay(5000);
}
