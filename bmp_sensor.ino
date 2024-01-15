#include <CanSatKit.h>

using namespace CanSatKit;

BMP280 bmp;


void initPressureSensor(){
  bmp.begin();
  bmp.setOversampling(16);
}

float getTemperature(){
  double temperature, pressure;
  bmp.measureTemperatureAndPressure(temperature, pressure);

  return (float)temperature;
}

float getPressure(){
  double temperature, pressure;
  bmp.measureTemperatureAndPressure(temperature, pressure);

  return (float)pressure;
}
