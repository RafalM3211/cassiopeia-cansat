#include <Wire.h>
#include "gps.h"

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  SerialUSB.println("\n cassiopeia cansat");

  initCo2Sensor();
}
 
 
void loop()
{
  int16_t co2=getCo2();
  SerialUSB.print("co2: ");
  SerialUSB.println(co2);

  struct GNRMC gps;
  gps = L76X_Gat_GNRMC();
  SerialUSB.print("status: ");
  SerialUSB.println(gps.Status);
  SerialUSB.print("latitude: ");
  SerialUSB.println(gps.Lat);
  SerialUSB.print("longitude: ");
  SerialUSB.println(gps.Lon);
  SerialUSB.print("velocity: ");
  SerialUSB.println(gps.Velocity);

  delay(1000);
}
