#include <Arduino.h>

int valor = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  valor = map(analogRead(A0), 0, 1023, 0, 255);
  Serial.print('Valor lido \n');
  Serial.print(valor);
  delay(1000);
  analogWrite(10,valor);
}