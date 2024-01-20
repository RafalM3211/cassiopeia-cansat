#include "DFRobot_OzoneSensor.h"

#define COLLECT_NUMBER  20              // collect number, the collection range is 1-100
/**
 * select i2c device address 
 *   OZONE_ADDRESS_0  0x70
 *   OZONE_ADDRESS_1  0x71
 *   OZONE_ADDRESS_2  0x72
 *   OZONE_ADDRESS_3  0x73
 */
#define Ozone_IICAddress OZONE_ADDRESS_3
DFRobot_OzoneSensor Ozone;

void initOzoneSensor(){
  Ozone.begin(Ozone_IICAddress);
  Ozone.setModes(MEASURE_MODE_PASSIVE);
}


int16_t getOzoneConcentration(){
  int16_t ozoneConcentration = Ozone.readOzoneData(COLLECT_NUMBER);
  return ozoneConcentration;
}