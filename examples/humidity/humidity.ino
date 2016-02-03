//
// FaBo Humidity Brick
//
// brick_i2c_humidity
//

#include <Wire.h>
#include <FaBoHumidity_HTS221.h>

FaBoHumidity_HTS221 fabo_hts221;

void setup()
{
  Serial.begin(9600); // シリアルの開始デバック用
   
  Serial.println("Checking I2C device...");
  
  if(fabo_hts221.searchDevice()){
    Serial.println("I am HTS221");
    fabo_hts221.configuration();
    fabo_hts221.powerOn();
  }
}

void loop()
{ 
  double temp = fabo_hts221.getTemperature()/10;
  double humidity = fabo_hts221.getHumidity()/10;

  Serial.print(temp);
  Serial.println(" C");
  Serial.print(humidity);
  Serial.println(" %");
  delay(1000);
}
