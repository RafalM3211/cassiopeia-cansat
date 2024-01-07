#include <Arduino.h>
#include <stdint.h>
#include "gps.h"
#define UBYTE   uint8_t
#define UWORD   uint16_t
#define UDOUBLE uint32_t
#define BUFFSIZE 800


uint8_t uart_receiveByte(){
  while(Serial.available()==0){
  }
  return Serial.read();
}

void uart_receiveString(char *data, uint16_t Num){  
  uint16_t i;
  while(1){
    if(Serial.available()){
        data[i] = Serial.read();
        i++;
        if(i >= Num){
            break;
          }
      }

   }

  data[Num-1] = '\0';
}


char buff_t[800]={0};


struct GNRMC L76X_Gat_GNRMC(){
    struct GNRMC gps;
    UWORD add = 0, word = 0, z = 0, i = 0;
    UDOUBLE Time = 0, latitude = 0, longitude = 0, velocity = 0;

    gps.Status = 0;

		gps.Time_H = 0;
    gps.Time_M = 0;
    gps.Time_S = 0;
	
    uart_receiveString(buff_t, 800);
    add = 0; 
    while(add < BUFFSIZE){
        if(buff_t[add] == '$' && buff_t[add+1] == 'G' && (buff_t[add+2] == 'N' || buff_t[add+2] == 'P')\
            && buff_t[add+3] == 'R' && buff_t[add+4] == 'M' && buff_t[add+5] == 'C'){
            word = 0;
            for(z = 0; word < 12; z++){
                if(buff_t[add+z]=='\0'){
                    break;
                }
                if(buff_t[add+z]==','){
                    word++;
                    if(word == 1){//The first comma is followed by time
                        Time = 0;
                        for(i = 0; buff_t[add+z+i+1] != '.'; i++){
                            if(buff_t[add+z+i+1]=='\0'){
                                break;
                            }   
                            if(buff_t[add+z+i+1] == ',')
                                break;
                            Time = (buff_t[add+z+i+1]-'0') + Time*10;
                        }
                        
                        gps.Time_H = Time/10000+8;
                        gps.Time_M = Time/100%100;
                        gps.Time_S = Time%100;
												if(gps.Time_H >= 24)
													gps.Time_H = gps.Time_H - 24;
                    }else if(word == 2){
                     //A indicates that it has been positioned
                     //V indicates that there is no positioning.
                        if(buff_t[add+z+1] == 'A'){
                             gps.Status = 1;
                        }else{
                             gps.Status = 0;
                        }
                    }else if(word == 3){
                        latitude = 0;
                        //If you need to modify, please re-edit the calculation method below.
                        for(i = 0; buff_t[add+z+i+1] != ','; i++){
                            if(buff_t[add+z+i+1] == '\0'){
                                break;
                            } 
                            if(buff_t[add+z+i+1] == '.'){
                                continue;
                            }
                            latitude = (buff_t[add+z+i+1]-'0') + latitude*10;
                        }
                        gps.Lat = latitude/10000000.0;
                    }else if(word == 4){
                        gps.Lat_area = buff_t[add+z+1];
                    }
                    else if(word == 5){
                        longitude = 0;
                        for(i = 0; buff_t[add+z+i+1] != ','; i++){
                            if(buff_t[add+z+i+1] == '\0'){
                                break;
                            } 
                            if(buff_t[add+z+i+1] == '.')
                                continue;
                            longitude = (buff_t[add+z+i+1]-'0') + longitude*10;
                        }
                        gps.Lon = longitude/10000000.0;
                    }else if(word == 6){
                        gps.Lon_area = buff_t[add+z+1];
                    }
                    else if(word == 7){
                      velocity = 0;
                        for(i = 0; buff_t[add+z+i+1] != ','; i++){
                            if(buff_t[add+z+i+1] == '\0'){
                                break;
                            } 
                            if(buff_t[add+z+i+1] == '.')
                                continue;
                            velocity = (buff_t[add+z+i+1]-'0') + velocity*10;
                        }
                        gps.Velocity = velocity/10;
                    }
                }
            }
            add = 0;
            break;
        }
        if(buff_t[add+5] == '\0'){
            add = 0;
						break;
        }
        add++;
        if(add > BUFFSIZE){
            add = 0;
            break;
        }
    }

  return gps;
}

