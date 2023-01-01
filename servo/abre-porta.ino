#include <Servo.h> 
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const int pinoServo = D7;
const char *wifiName =  "Micro";
const char *password =  "12345678";
const String trueReturn = "true";
 
Servo servo;
int pos;

void setup (){
  servo.attach(pinoServo);
  servo.write(0);

  Serial.begin(115200);
  delay(10);           
  
  Serial.println("");
  wifiConnect();
}
void loop(){
  HTTPClient http;
  http.begin("http://labdoor.azurewebsites.net/authentication/should-open/7890123");  

  Serial.println("Iniciando requisição");
  int httpCode = http.GET();
  Serial.println("Requisição realizada: ");
  Serial.print(httpCode);
  if (httpCode > 0) { 
    String ret = http.getString();
    Serial.println("Retorno: ");
    Serial.println(ret);
    
    if(ret == trueReturn){
      for(pos = 0; pos < 180; pos++){
        servo.write(pos);
        delay(5);
      }
      delay(1000);
      for(pos = 180; pos >= 0; pos--){
        servo.write(pos);
        delay(5); 
      }
    } 
  }
  http.end();
  Serial.println("Requisição finalizada");
  delay(30000);
}

void wifiConnect(){
  Serial.println("Conectando na rede ");
  Serial.println(wifiName);
  WiFi.begin(wifiName, password); 
  while (WiFi.status() != WL_CONNECTED) 
  {
   delay(500);
   Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi conectado"); 
}
