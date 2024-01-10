// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include "DHT.h"

#define DHTPIN 5 

//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

void initHumiditySensor(){
  dht.begin();
}

float getHumidity(){
  float humidity = dht.readHumidity();
  if (isnan(humidity)) {
    SerialUSB.println("Failed to read from DHT sensor!");
    return 0;
  }
  return humidity;
}
