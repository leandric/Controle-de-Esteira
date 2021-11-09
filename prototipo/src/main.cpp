#include <Arduino.h>

#include <LiquidCrystal.h>

//Diplay
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Ponte H
const int 
enable_m1 = 10,
enable_m2 =7,
sentido1_m1 = 8,
sentido1_m2 = 6,
sentido2_m1 = 9,
sentido2_m2 = A5;

//Sensor TMP
int sensor = A3;
float temperatura;

//Transistor
int N = A4;


//Power
const int power = 13;
bool statusPower;

int teste= 1;

void setup() {
  //lcd.begin(16, 2);
  //lcd.print("Temp: 26C Velocidade em 30%");
  //Ponte H
  pinMode(enable_m1,OUTPUT);
  pinMode(enable_m2,OUTPUT);
  pinMode(sentido1_m1,OUTPUT);
  pinMode(sentido2_m1,OUTPUT);
  pinMode(sentido1_m2,OUTPUT);
  pinMode(sentido2_m2,OUTPUT);

  //Transistor
  pinMode(N, OUTPUT);

  //Sensor de temperatura
  pinMode(sensor, INPUT);
  Serial.begin(9600);

  //Setup do LCD
  lcd.begin(16,2);

  //Motores sempre ativos
  digitalWrite(enable_m1, HIGH);
  digitalWrite(enable_m2, HIGH);
}

void loop() {
  
  if (digitalRead(power))
  {
    //Tmp ºC = (( NRA * 4,8828125mV  ) - 97,65625 mV ) * 0,1 ºC) - 40 ºC 
    temperatura = ((( analogRead(sensor) * 4.8828125  ) - 97.65625) * 0.1) - 40;
    motores(0);
    analogWrite(N, 128.86);

    if (temperatura <= 0.0)
    {
      display("Motor 0%", "Temp. " + String(temperatura) + "C", 300);
    }
    else if (temperatura >= 0.1 and temperatura <= 10.0)
    {
      display("Motor 10%", "Temp. " + String(temperatura) + "C", 300);
    } 
    else if (temperatura >= 10.1 and temperatura <= 20.0)
    {
      display("Motor 20%", "Temp. " + String(temperatura) + "C", 300);
    } 
    else if (temperatura >= 20.1 and temperatura <= 30.0)
    {
      display("Motor 30%", "Temp. " + String(temperatura) + "C", 300);
    } 
    else if (temperatura >= 30.1 and temperatura <= 40.0)
    {
      display("Motor 40%", "Temp. " + String(temperatura) + "C", 300);
    } 
    else if (temperatura >= 40.1 and temperatura <= 50.0)
    {
      display("Motor 50%", "Temp. " + String(temperatura) + "C", 300);
    } 
    else if (temperatura >= 50.1 and temperatura <= 60.0)
    {
      display("Motor 60%", "Temp. " + String(temperatura) + "C", 300);
    } 
    else if (temperatura >= 60.1 and temperatura <= 70.0)
    {
      display("Motor 70%", "Temp. " + String(temperatura) + "C", 300);
    } 
        else if (temperatura >= 70.1 and temperatura <= 80.0)
    {
      display("Motor 80%", "Temp. " + String(temperatura) + "C", 300);
    } 
        else if (temperatura >= 80.1 and temperatura <= 90.0)
    {
      display("Motor 90%", "Temp. " + String(temperatura) + "C", 300);
    } 
        else if (temperatura >= 91.1 and temperatura <= 100.0)
    {
      display("Motor 100%", "Temp. " + String(temperatura) + "C", 300);
    } 
    else if (temperatura > 100.1)
    {
      display("CRITICO 100%", "Temp. " + String(temperatura) + "C", 300);
    } 

  }else
  {
    display("off","   ", 3000);
  }
}

void display(String texto1, String texto2, int Delay) {
  // Recebe duas Strings para serem exibidas no visor lcd
  //Atualiza em 5 segundos
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print(texto1);
    lcd.setCursor(0,1);
    lcd.print(texto2);
    delay(Delay);
}

void motores(int comando) {
  switch (comando)
  {
    case 0:
      digitalWrite(sentido1_m1,HIGH);
      digitalWrite(sentido1_m2,HIGH);
      digitalWrite(sentido2_m1, LOW);
      digitalWrite(sentido2_m2, LOW);
    break;

    case 1:
      digitalWrite(sentido1_m1, LOW);
      digitalWrite(sentido1_m2, LOW);
      digitalWrite(sentido2_m1, HIGH);
      digitalWrite(sentido2_m2, HIGH);
    break;
  }
}

void potencia(float pt)
{
  motores(0);
  analogWrite(N, pt);
}