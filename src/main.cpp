#include <Arduino.h>
#include <DHT.h>
#include <DHT_U.h>

#define led4 2
#define led3 3
#define led2 4
#define led1 5
#define latch 7
#define data 8
#define clock 9
#define dht_pin 10
#define status 11

DHT dht(dht_pin, DHT11);

void latch_enable()
{
  digitalWrite(latch, HIGH);
  delayMicroseconds(500);
  digitalWrite(latch, LOW);
}

void clock_enable()
{
  digitalWrite(clock, HIGH);
  delayMicroseconds(500);
  digitalWrite(clock, LOW);
  delayMicroseconds(500);
}

void send_Data(int x)
{
  for (int i = 0; i < 8; i++)
  {
    if (x >> i & 1)
      digitalWrite(data, HIGH);
    else
      digitalWrite(data, LOW);
    clock_enable();
  }
  latch_enable();
}

void port_enable(int x)
{
  digitalWrite(x, HIGH);
}

void port_disable(int x)
{
  digitalWrite(x, LOW);
}

void clear()
{
  send_Data(0xFF);
}

int numberNoDot[] =
    {0b00000011, 0b10011111, 0b00100101,
     0b00001101, 0b10011001, 0b01001001,
     0b01000001, 0b00011111, 0b00000001, 0b00001001};

int numberWithDot[] =
    {0b00000010, 0b10011110, 0b00100100,
     0b00001100, 0b10011000, 0b01001000,
     0b01000000, 0b00011110, 0b00000000, 0b00001000};

void setup()
{
  // put your setup code here, to run once:
  pinMode(latch, OUTPUT);
  pinMode(data, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(status, INPUT);
  Serial.begin(9600);
  dht.begin();
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(latch, LOW);
  digitalWrite(clock, LOW);
}
int count = 1;
void loop()
{
  // put your main code here, to run repeatedly:
  int buttonStatus = digitalRead(status);
  double t = dht.readTemperature();
  double h = dht.readHumidity();
  Serial.print("Temperature: ");
  Serial.println(t);
  Serial.print("Humidity: ");
  Serial.println(h);
  int t1 = (int)t / 10;
  int t2 = (int)t % 10;
  int t3 = (int)(t * 10) % 10;
  int t4 = (int)(t * 100) % 10;
  int h1 = (int)h / 10;
  int h2 = (int)h % 10;
  int h3 = (int)(h * 10) % 10;
  int h4 = (int)(h * 100) % 10;
  if (buttonStatus)
  {
    ++count;
    if (count == 10)
      count = 1;
  }
  // Serial.print("Counter: ");
  // Serial.println(count);
  if (count % 2 == 0)
  {
    for (int i = 1; i < 25; i++)
    {

      clear();
      port_enable(led1);
      send_Data(numberNoDot[t1]);
      delay(2);
      port_disable(led1);
      clear();
      port_enable(led2);
      send_Data(numberWithDot[t2]);
      delay(2);
      port_disable(led2);
      clear();
      port_enable(led3);
      send_Data(numberNoDot[t3]);
      delay(2);
      port_disable(led3);
      clear();
      port_enable(led4);
      send_Data(numberNoDot[t4]);
      delay(2);
      port_disable(led4);
    }
  }
  else
  {
    for (int i = 1; i < 25; i++)
    {

      clear();
      port_enable(led1);
      send_Data(numberNoDot[h1]);
      delay(2);
      port_disable(led1);
      clear();
      port_enable(led2);
      send_Data(numberWithDot[h2]);
      delay(2);
      port_disable(led2);
      clear();
      port_enable(led3);
      send_Data(numberNoDot[h3]);
      delay(2);
      port_disable(led3);
      clear();
      port_enable(led4);
      send_Data(numberNoDot[h4]);
      delay(2);
      port_disable(led4);
    }
  }
}