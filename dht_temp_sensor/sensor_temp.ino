#include <DHT.h>
#include <DHT_U.h>
#define DHT11PIN 4
#define DHTTYPE DHT11

const int initializeDelayTime = 2000;

DHT dht(DHT11PIN, DHTTYPE);

void setup() {
  Serial.begin(9600); 
  Serial.println("Inicio da leitura do sensor:");
  dht.begin();
}

void loop() {   
  delay(initializeDelayTime);
  float hum = dht.readHumidity();  
  float temp = dht.readTemperature();

  if (isnan(hum) || isnan(temp)) {
    Serial.println("Falha na leitura!");
    return;
  }

  float sensacaoTermica = dht.computeHeatIndex(temp, hum, false);

  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" *C ");  
  Serial.print("Heat index: ");
  Serial.print(sensacaoTermica);
  Serial.print(" *C ");
  Serial.println();
}
