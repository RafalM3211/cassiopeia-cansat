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

  String co2=getCo2();
  data+=co2+";";
  SerialUSB.print(" co2: ");
  SerialUSB.print(co2);

  String humidity=getHumidity();
  data+=humidity+";";
  SerialUSB.print(" humidity: ");
  SerialUSB.print(humidity);


  String temperature=getTemperature();
  data+=temperature+";";
  SerialUSB.print(" temperature: ");
  SerialUSB.print(temperature);

  String pressure=getPressure();
  data+=pressure+";";
  SerialUSB.print(" pressure: ");
  SerialUSB.print(pressure);

  String ozoneConcentration=getOzoneConcentration();
  data+=ozoneConcentration;
  SerialUSB.print(" ozone concentration: ");
  SerialUSB.print(ozoneConcentration);

  struct GNRMC gps;
  gps = getGpsData();
  SerialUSB.print(" status: ");
  SerialUSB.print(gps.Status);
  data+=String(gps.Status)+";";

  SerialUSB.print(" latitude: ");
  SerialUSB.print(gps.Lat);
  data+=String(gps.Lat)+";";

  SerialUSB.print(" longitude: ");
  SerialUSB.print(gps.Lon);
  data+=String(gps.Lon)+";";

  SerialUSB.print(" velocity: ");
  SerialUSB.print(gps.Velocity);
  data+=String(gps.Velocity)+";";
  
  SerialUSB.print(" Timestamp: ");
  SerialUSB.print(gps.Time_H);
  SerialUSB.print(gps.Time_M);
  SerialUSB.print(gps.Time_S);
  data+=String(gps.Time_H)+";";
  data+=String(gps.Time_M)+";";
  data+=String(gps.Time_S)+";";

  SerialUSB.println("data: ");
  SerialUSB.println(data);


  transmit(data);
  delay(500);
}
