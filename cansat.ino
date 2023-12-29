#include <Wire.h>
 

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  //while (!Serial);             // Leonardo: wait for serial monitor
  SerialUSB.println("\n cassiopeia cansat");

  initCo2Sensor();
}
 
 
void loop()
{
  //scan();
  int16_t co2=getCo2();
  SerialUSB.println(co2);
  delay(100);
}
