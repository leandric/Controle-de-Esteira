#include <Arduino.h>
int valor = 0;

//2 --> 106
//10 -->125
//Velocidade --> 0 - 255

//Pinos display
int A = 11; 
int B = 10;
int C = 7;
int D = 8;
int E = 9;
int F = 12;
int G = 13;
int DP = 0;

void setup()
{
  Serial.begin(9600);
  //Pinos do display
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);
}

void loop()
{
  valor = analogRead(A0);
  Serial.println(valor);
  if (valor <= 106) {
    analogWrite(3,round(255 * 0.5));
    display(1);
    Serial.println("Velocidade 1");
  } else if (valor > 106 && valor <= 125  )
  {
    analogWrite(3,round(255 * 0.75));
    display(2);
    Serial.println("Velocidade 2");
  } else
  {
    analogWrite(3,round(255 * 1));
    display(3);
    Serial.println("Velocidade 3");
  }
}

void display(int numero)
{
    switch (numero) {
      case 1:
      	Serial.println("caso1");
        digitalWrite(A,LOW);
        digitalWrite(B,HIGH);
        digitalWrite(C,HIGH);
        digitalWrite(D,LOW);
        digitalWrite(E,LOW);
        digitalWrite(F,LOW);
        digitalWrite(G,LOW);
        digitalWrite(DP,LOW);
        break;
      case 2:
        digitalWrite(A,HIGH);
        digitalWrite(B,HIGH);
        digitalWrite(C,LOW);
        digitalWrite(D,HIGH);
        digitalWrite(E,HIGH);
        digitalWrite(F,LOW);
        digitalWrite(G,HIGH);
        digitalWrite(DP,LOW);
        break;
      case 3:
      	Serial.println("caso3");
        digitalWrite(A,HIGH);
        digitalWrite(B,HIGH);
        digitalWrite(C,HIGH);
        digitalWrite(D,HIGH);
        digitalWrite(E,LOW);
        digitalWrite(F,LOW);
        digitalWrite(G,HIGH);
        digitalWrite(DP,LOW);
        break;
    }
}