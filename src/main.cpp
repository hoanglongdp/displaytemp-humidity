#include <Arduino.h>
#include "DHT.h"

#define DATA 5
#define ST 4
#define SH 3

const int DHT_Pin = 2;
const int DHT_Type = DHT11;
DHT dht(DHT_Pin, DHT_Type);

void SelectPort(int num);
void PrintNumber(int num);
void Clear();


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(ST, OUTPUT);
  pinMode(SH, OUTPUT);
  pinMode(DATA, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int humi = dht.readHumidity();
  int temp = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.println(humi);
  Serial.print("Temperature: ");
  Serial.println(temp);
  delay(5);
  int num1 = humi / 10;
  int num2 = humi % 10;
  int num3 = temp / 10;
  int num4 = temp % 10;
  for (int i=0; i<25; i++) {
    SelectPort(1);
    PrintNumber(num1);
    delay(5);
    SelectPort(2);
    PrintNumber(num2);
    delay(5);
    SelectPort(3);
    PrintNumber(num3);
    delay(5);
    SelectPort(4);
    PrintNumber(num4);
    delay(5);
  }
    

  // SelectPort(2);
  // for (int i=0; i<=9; i++) {
  //   PrintNumber(i);
  //   delay(1000);
  // }
}

void SelectPort(int num) {
  switch (num)
  {
  case 1:
    digitalWrite(ST, LOW);
    shiftOut(DATA, SH, MSBFIRST, 1);
    digitalWrite(ST, HIGH);
    break;
  case 2:
    digitalWrite(ST, LOW);
    shiftOut(DATA, SH, MSBFIRST, 2);
    digitalWrite(ST, HIGH);
    break;
  case 3:
    digitalWrite(ST, LOW);
    shiftOut(DATA, SH, MSBFIRST, 4);
    digitalWrite(ST, HIGH);
    break;
  case 4:
    digitalWrite(ST, LOW);
    shiftOut(DATA, SH, MSBFIRST, 8);
    digitalWrite(ST, HIGH);
    break;
  case 5:
    digitalWrite(ST, LOW);
    shiftOut(DATA, SH, MSBFIRST, 15);
    digitalWrite(ST, HIGH);
    break;
  }
}

void PrintNumber(int num) {
  switch (num) {
    case 0:
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(13, HIGH);
      break;
    case 1:
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(13, HIGH);
      break;
    case 2:
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      break;
    case 3:
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      break;
    case 4:
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      break;
    case 5:
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      break;
    case 6:
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      break;
    case 7:
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
      digitalWrite(13, HIGH);
      break;
    case 8:
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      break;
    case 9:
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      break;
  }
}

void Clear() {
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
}