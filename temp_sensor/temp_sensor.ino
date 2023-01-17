#include "DHT.h"

const int TEMP_SENSOR = 9;
const int SERIAL_VEL = 9600;

/* 
 * The minimum interval is defined by the sensor datasheet as 2 seconds. 
 * The time to read the temperature is between 250ms and 2s.
 * The communication occours between a protocol that is implemented by the DHT.h library.
 */
const int READING_INTERVAL = 2000;

bool isValidReading(int humidity, int temperature);
void printErrorMessage();
void printData(int humidity, int temperature);
void handleSensorResponse(int humidity, int temperature);

// The sensor model is DHT11.
DHT dht(TEMP_SENSOR, DHT11);

void setup() {
  Serial.begin(SERIAL_VEL);
  dht.begin();
}

void loop() {
  delay(READING_INTERVAL);
  
  int temperature = dht.readTemperature();
  int humidity = dht.readHumidity();
  
  handleSensorResponse(humidity, temperature);
}

bool isValidReading(int humidity, int temperature)
{
  return isnan(humidity) || isnan(temperature);
}

void printErrorMessage()
{
  Serial.println("Error reading DHT Sensor!");
}

void printData(int humidity, int temperature)
{
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" *C ");
    
    Serial.print("\t");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print(" %\t"); 
    
    Serial.println();
}

void handleSensorResponse(int humidity, int temperature)
{
  if (isValidReading(humidity, temperature)) {
    printErrorMessage();
  }
  else { 
    printData(humidity, temperature);
  }
}
