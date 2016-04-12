/*************************************************** 
 This is an Example for the FaBo Humidity I2C Brick.

  http://fabo.io/208.html

 author:FaBo<info@fabo.io>
 maintainer:Akira Sasaki<akira@fabo.io>

 Released under APACHE LICENSE, VERSION 2.0
  http://www.apache.org/licenses/
 ****************************************************/

#include <Wire.h>
#include <FaBoHumidity_HTS221.h>

FaBoHumidity_HTS221 faboHumidity;

void setup() {
  Serial.begin(9600);
  Serial.println("RESET");
  Serial.println();

  Serial.println("configuring device.");

  if (faboHumidity.begin()) {
    Serial.println("configured FaBo Humidity Brick");
  } else {
    Serial.println("device error");
    while(1);
  }
}

void loop() { 
  double temp = faboHumidity.getTemperature();
  double humidity = faboHumidity.getHumidity();

  Serial.print(temp);
  Serial.println(" C");
  Serial.print(humidity);
  Serial.println(" %");
  delay(1000);
}
