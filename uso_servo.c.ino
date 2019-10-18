#include <Servo.h>
 
const int pinoServo = 6;
 
Servo servo;
int pos;
 
void setup (){
  servo.attach(pinoServo);
  servo.write(0);
}
void loop(){
  for(pos = 0; pos < 180; pos++){ //PARA "pos" IGUAL A 0, ENQUANTO "pos" MENOR QUE 180, INCREMENTA "pos"
    servo.write(pos); //ESCREVE O VALOR DA POSIÇÃO QUE O SERVO DEVE GIRAR
    delay(05); //INTERVALO DE 15 MILISSEGUNDOS
  }
  delay(1000); //INTERVALO DE 1 SEGUNDO
  for(pos = 180; pos >= 0; pos--){ //PARA "pos" IGUAL A 180, ENQUANTO "pos" MAIOR OU IGUAL QUE 0, DECREMENTA "pos"
    servo.write(pos); //ESCREVE O VALOR DA POSIÇÃO QUE O SERVO DEVE GIRAR
    delay(15); //INTERVALO DE 15 MILISSEGUNDOS
  }
}
