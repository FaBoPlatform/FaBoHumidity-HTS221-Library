//
// FaBo Humidity Brick
//
// brick_i2c_humidity
//

#include <Wire.h>
#include "fabo-hts221.h"

void setup()
{
  Serial.begin(115200); // シリアルの開始デバック用
   
  Serial.println("Checking I2C device...");
  
  if(faboHumidity.SearchDevice()){
    Serial.println("I am HTS221");
    faboHumidity.configuration();
    faboHumidity.powerOn();
  }
}

void loop()
{ 
  double temp = faboHumidity.getTemperature()/10;
  double humidity = faboHumidity.getHumidity()/10;

  Serial.println(temp);
  Serial.println(" C");
  Serial.print(humidity);
  Serial.println(" %");
  delay(1000);
}
