#ifndef GPS_H
#define GPS_H
#include <stdint.h>

typedef struct GNRMC{
	double Lon;     //GPS Latitude and longitude
	double Lat;
  char Lon_area;
  char Lat_area;
  uint8_t Time_H;   //Time
  uint8_t Time_M;
  uint8_t Time_S;
  uint8_t Status;   //1:Successful positioning 0：Positioning failed
  uint8_t Velocity;
};

struct GNRMC L76X_Gat_GNRMC();

#endif