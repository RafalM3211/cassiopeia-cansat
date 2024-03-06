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
