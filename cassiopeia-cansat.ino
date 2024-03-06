#include "gps.h"

void setup()
{
  Serial.begin(9600);
  SerialUSB.print("\n cassiopeia cansat");

  initPressureSensor();
  initCo2Sensor();
  initHumiditySensor();
  initOzoneSensor();
  initRadio();
} 


void loop()
{
  String data="";

  struct GNRMC gps;
  gps = getGpsData();
  
  SerialUSB.print(" Timestamp: ");
  SerialUSB.print(gps.Time_H+";");
  SerialUSB.print(gps.Time_M+";");
  SerialUSB.print(gps.Time_S+";");
  data+=String(gps.Time_H)+";";
  data+=String(gps.Time_M)+";";
  data+=String(gps.Time_S)+";";
  
  SerialUSB.print("\n status: ");
  SerialUSB.print(gps.Status);
  data+=String(gps.Status)+";";

  SerialUSB.print("\n latitude: ");
  SerialUSB.print(gps.Lat);
  data+=String(gps.Lat)+";";

  SerialUSB.print("\n longitude: ");
  SerialUSB.print(gps.Lon);
  data+=String(gps.Lon)+";";

  SerialUSB.print("\n velocity: ");
  SerialUSB.print(gps.Velocity);
  data+=String(gps.Velocity)+";";

  //sensors
  
  String temperature=getTemperature();
  data+=temperature+";";
  SerialUSB.print("\n temperature: ");
  SerialUSB.print(temperature);

  String pressure=getPressure();
  data+=pressure+";";
  SerialUSB.print("\n pressure: ");
  SerialUSB.print(pressure);

  String co2=getCo2();
  data+=co2+";";
  SerialUSB.print("\n co2: ");
  SerialUSB.print(co2);

  String humidity=getHumidity();
  data+=humidity+";";
  SerialUSB.print("\n humidity: ");
  SerialUSB.print(humidity);

  String ozoneConcentration=getOzoneConcentration();
  data+=ozoneConcentration;
  SerialUSB.print("\n ozone concentration: ");
  SerialUSB.print(ozoneConcentration);

  transmit(data);
  delay(500);
}
