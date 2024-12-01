/*
 * Kết nối:
            DHT11                           Arduino
            VCC                               5V
            GND                               GND
            OUT                               2

 */

 /*
 * Kết nối: LCD
            LCD                             Arduino
            VCC                               5V
            GND                               GND
            SCL                               A5
            SDA                               A4

   Nạp code mở Serial Monitor chọn No line ending, baud 9600.
 */
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);
 #include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define mua = 3;
void setup()
{
    Serial.begin(9600);     // giao tiếp Serial với baudrate 9600
    dht.begin();
    lcd.init();                      // initialize the lcd 
  lcd.backlight();
  pinMode(mua, INPUT_PULLUP);
}
 
void loop()
{
    loat h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
    String ttmua;
    if(digitalRead(mua) == 0){
      ttmua = "  TROI DANG MUA ";
    }
    else{
      ttmua = " TROI DANG TANH ";
    }
    /* In kết quả ra Serial Monitor */
    Serial.print(distance);
    Serial.println("cm");
    if(distance < 4) distance =0;
    int mucnuoc = map(distance,0,docaoly,0,100);
    lcd.setCursor(0, 0);
  lcd.print("T:    *C H:    %");
  lcd.setCursor(2, 0);
  lcd.print(t);
  lcd.setCursor(11, 0);
  lcd.print(h);
  lcd.setCursor(0, 1);
  lcd.print(ttmua);
    delay(200);
}
