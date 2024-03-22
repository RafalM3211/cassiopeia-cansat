#include "gps.h"

#define LOG_MODE false  //change to true to enable logging sensor data



void setup()
{
  Serial.begin(9600);
  SerialUSB.begin(9600);
  SerialUSB.print("\n cassiopeia cansat");

  initPressureSensor();
  initCo2Sensor();
  initHumiditySensor();
  initOzoneSensor();
  initRadio();

  initSD();
  //initRecovery();
} 


void loop()
{
  String data="";

  struct GNRMC gps;
  gps = getGpsData();

  data+=String(gps.Time_H)+";";
  data+=String(gps.Time_M)+";";
  data+=String(gps.Time_S)+";";
  
  data+=String(gps.Status)+";";
  data+=String(gps.Lat)+";";
  data+=String(gps.Lon)+";";
  data+=String(gps.Velocity)+";";

  //sensors
  
  String temperature=getTemperature();
  data+=temperature+";";

  String pressure=getPressure();
  data+=pressure+";";

  String altitude=getAltitude();
  data+=altitude+";";

  String co2=getCo2();
  data+=co2+";";

  String methane=getMethane();
  data+=methane+";";

  String humidity=getHumidity();
  data+=humidity+";";

  String ozoneConcentration=getOzoneConcentration();
  data+=ozoneConcentration;


  if(LOG_MODE){
    SerialUSB.print(" Timestamp: ");
    SerialUSB.print(gps.Time_H+";");
    SerialUSB.print(gps.Time_M+";");
    SerialUSB.print(gps.Time_S+";");

    SerialUSB.print("\n status: ");
    SerialUSB.print(gps.Status);

    SerialUSB.print("\n latitude: ");
    SerialUSB.print(gps.Lat);

    SerialUSB.print("\n longitude: ");
    SerialUSB.print(gps.Lon);

    SerialUSB.print("\n velocity: ");
    SerialUSB.print(gps.Velocity);

    SerialUSB.print("\n temperature: ");
    SerialUSB.print(temperature);

    SerialUSB.print("\n pressure: ");
    SerialUSB.print(pressure);

    SerialUSB.print("\n altitude: ");
    SerialUSB.print(altitude);

    SerialUSB.print("\n co2: ");
    SerialUSB.print(co2);

    SerialUSB.print("\n methane: ");
    SerialUSB.print(methane);

    SerialUSB.print("\n humidity: ");
    SerialUSB.print(humidity);

    SerialUSB.print("\n ozone concentration: ");
    SerialUSB.print(ozoneConcentration + "\n");
  }

  SerialUSB.println(data);
  transmit(data);


  writeToSD("a");
  //checkAndActivateRecovery("232");
  delay(500);
}
