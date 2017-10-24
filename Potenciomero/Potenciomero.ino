/*
 * Entrada analógica
 * por DojoDave <http://www.0j0.org>
 *
 * Liga e desliga um LED conectado ao pino digital 13. O tempo
 * que o LED permanece ligado ou desligado depende do valor
 * obtido pelo analogRead(). No caso mais simples, conectamos
 * um potenciômetro ao pino analógico 2.
 */

int potPin = 2;    // selecione o pino de entrada ao potenciômetro
int ledPin = 13;   // selecione o pino ao LED
int val = 0;       // variável a guardar o valor proveniente do sensor

void setup() {
  pinMode(ledPin, OUTPUT);  // declarar o pino ledPin como saída
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  val = analogRead(potPin);    // ler o valor do potenciômetro
  if(val > 300){
    digitalWrite(ledPin, HIGH);  // ligar o ledPin  
  }
  else{
    digitalWrite(ledPin, LOW);   // desligar o ledPin  
  }

  if(val > 500){
    digitalWrite(12, HIGH);  // ligar o ledPin  
  }
  else{
    digitalWrite(12, LOW);   // desligar o ledPin  
  }

  if(val > 750){
    digitalWrite(11, HIGH);  // ligar o ledPin  
  }
  else{
    digitalWrite(11, LOW);   // desligar o ledPin  
  }
}
