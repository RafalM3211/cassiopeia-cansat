#include "gps.h"

void setup()
{
  Serial.begin(9600);
  SerialUSB.println("\n cassiopeia cansat");

  initPressureSensor();
  initCo2Sensor();
  initHumiditySensor();
  initOzoneSensor();
}
 
 
void loop()
{
  int16_t co2=getCo2();
  SerialUSB.print("co2: ");
  SerialUSB.println(co2);

  float humidity=getHumidity();
  SerialUSB.print("humidity: ");
  SerialUSB.println(humidity);

  float temperature=getTemperature();
  SerialUSB.print("temperature: ");
  SerialUSB.println(temperature);

  float pressure=getPressure();
  SerialUSB.print("pressure: ");
  SerialUSB.println(pressure);

  int16_t ozoneConcentration=getOzoneConcentration();
  SerialUSB.print("ozone concentration: ");
  SerialUSB.println(ozoneConcentration);

  struct GNRMC gps;
  gps = getGpsData();
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
