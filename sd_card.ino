#include <SPI.h>
#include <SD.h>

void initSD(){
  if (!SD.begin(11)) {
    Serial.println("Card failed, or not present");
  }
}

void writeToSD(String data){
  File dataFile = SD.open("data.txt", FILE_WRITE);
  if(dataFile){
    dataFile.println(data);
    dataFile.close();
  }
  else {
    SerialUSB.println("error opening data.txt");
  }
}