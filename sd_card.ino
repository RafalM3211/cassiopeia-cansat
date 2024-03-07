#include <SPI.h>
#include <SD.h>

void initSD(){
  if (!SD.begin(11)) {
    SerialUSB.println("Card failed, or not present");
  }
  else{
    SerialUSB.println("Card initialized");
  }
}

void writeToSD(String data){
  File dataFile = SD.open("data.txt", FILE_WRITE);
  if(dataFile){
    dataFile.println(data+" | eof + \n");
    dataFile.close();
  }
  else {
    SerialUSB.println("error opening data.txt");
  }
}