#include <CanSatKit.h>
#include <math.h>

using namespace CanSatKit;

BMP280 bmp;




void initPressureSensor(){
  bmp.begin();
  bmp.setOversampling(16);
}

String getTemperature(){
  double temperature, pressure;
  bmp.measureTemperatureAndPressure(temperature, pressure);

  return String(temperature);
}

String getPressure(){
  double temperature, pressure;
  bmp.measureTemperatureAndPressure(temperature, pressure);
  return String(pressure);
}

String getAltitude(){
  float seaLevelhPa=1020;  //TO BEDZIE TRZEBA ZMIENIAC W ZALEZNOSCI OD TEGO JAKIE JEST CISNIENIE NAD MORZEM

  double temperature, pressure;
  bmp.measureTemperatureAndPressure(temperature, pressure);

  float altitude =  (pow(seaLevelhPa/pressure, 0.1903) - 1)*(temperature+273.15)/0.0065;

  return String(altitude);
}