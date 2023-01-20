const int VRX = A4;
const int VRY = A5;
const int SW = 2;
const int SERIAL_VEL = 9600;
const int LOOP_DELAY = 10;

struct joystick {
  int x;
  int y;
  int button;
};

void setup() 
{
  Serial.begin(SERIAL_VEL);
  pinMode(VRX, INPUT);
  pinMode(VRY, INPUT);
  pinMode(SW, INPUT_PULLUP);
}

void loop() 
{
  joystick reading = read_joystick();
  print_joystick_reading(reading);

  delay(LOOP_DELAY);
}

joystick read_joystick()
{
  int x = analogRead(VRX);
  int y = analogRead(VRY);
  int button = digitalRead(SW);

  return (joystick){x, y, button};
}

void print_joystick_reading(joystick reading)
{
  Serial.print("Reading on VRX: ");
  Serial.print("\t");
  Serial.print(reading.x);
  Serial.print("\t");
  Serial.print("Reading on VRY: ");
  Serial.print("\t");
  Serial.print(reading.y);
  Serial.print("\t");
  Serial.print("Button: ");
  Serial.println(reading.button);
}
