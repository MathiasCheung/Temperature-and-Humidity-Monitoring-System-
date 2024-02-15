#include <DHT.h>
#include <LiquidCrystal.h>

//sensor
int DHT_pin = 7;

//LCD
LiquidCrystal Lcd_1(12,11,5,4,3,2);


DHT dht(DHT_pin, DHT11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();

  //set up LCD
  Lcd_1.begin(16,2);
  //Lcd_1.print("hello world!");

}

void loop() {
  // put your main code here, to run repeatedly:
  Lcd_1.clear();
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();

  Serial.print("Temp: ");
  Serial.println(temp);
  Serial.print("Humidity: ");
  Serial.println(humi);

  // print on lcd
  Lcd_1.print("Temp: ");
  Lcd_1.print(temp);
  Lcd_1.setCursor(0,1);
  Lcd_1.print("Humidity: ");
  Lcd_1.print(humi);

  

  delay(1000);

}
