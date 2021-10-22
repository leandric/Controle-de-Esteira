#include <Arduino.h>
int valor = 0;

//2 --> 108
//10 -->125
//Velocidade --> 0 - 255


void setup()
{
  Serial.begin(9600);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

}

void loop()
{
  valor = analogRead(A0);
  Serial.println(valor);
  if (valor < 108) {
    analogWrite(10,round(255 * 0.5));
    display(1);
    Serial.println("Velocidade 1");
  } else if (valor < 125 )
  {
    analogWrite(10,round(255 * 0.75));
    display(2);
    Serial.println("Velocidade 2");
  } else
  {
    analogWrite(10,round(255 * 1));
    display(3);
    Serial.println("Velocidade 3");
  }
}

void display(int numero)
{
    switch (numero) {
      case 1:
      	Serial.println("caso1");
        digitalWrite(1, LOW);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        delay(1000); // Wait for 1000 millisecond(s)
        digitalWrite(1, HIGH);
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH); 
        break;
      case 2:
      	Serial.println("caso2");
        digitalWrite(1, LOW);
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        delay(1000); // Wait for 1000 millisecond(s)
        break;
      case 3:
      	Serial.println("caso3");
        digitalWrite(1, HIGH);
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        delay(1000); // Wait for 1000 millisecond(s)
        digitalWrite(1, HIGH);
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH); 
        break;
    }
}