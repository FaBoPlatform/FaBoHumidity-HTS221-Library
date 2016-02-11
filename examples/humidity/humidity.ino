//
// FaBo Humidity Brick
//
// brick_i2c_humidity
//

#include <Wire.h>
#include <FaBoHumidity_HTS221.h>

FaBoHumidity_HTS221 faboHumidity;

void setup()
{
  Serial.begin(9600); // シリアルの開始デバック用
   
  Serial.println("Checking I2C device...");
  
  if(faboHumidity.searchDevice()){
    Serial.println("I am HTS221");
    faboHumidity.configuration();
    faboHumidity.powerOn();
  }
}

void loop()
{ 
  double temp = faboHumidity.getTemperature()/10;
  double humidity = faboHumidity.getHumidity()/10;

  Serial.print(temp);
  Serial.println(" C");
  Serial.print(humidity);
  Serial.println(" %");
  delay(1000);
}
