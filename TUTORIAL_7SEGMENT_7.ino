/*
   TUTORIAL SEVEN SEGMENT PADA ARDUINO
   MENGGUNAKAN CHIP TM1637
   MENAMPILKAN SUHU DAN KELEMBABAN UDARA DHT11

   Pinout :
   CLK -> D10
   DIO -> D11

   DHT signal -> D12
*/

#include <Arduino.h>
#include <TM1637Display.h>
#include <dht.h>

// Module connection pins (Digital Pins)
#define CLK 10
#define DIO 11
#define DHT_PIN 12
#define TEST_DELAY 2000

//inisiasi TM1637
TM1637Display display(CLK, DIO);

//inisiasi dht
dht SENSOR_DHT;

void setup()
{
  display.setBrightness(0x0f);
}

void loop()
{

  int cek = SENSOR_DHT.read11(DHT_PIN);

  // Menampilkan angka suhu rata kanan
  display.showNumberDec(SENSOR_DHT.temperature, false,2,0);
  delay(TEST_DELAY);
  display.clear();
  display.showNumberDec(SENSOR_DHT.humidity, false,2,2);
  delay(TEST_DELAY);
  display.clear();

}
