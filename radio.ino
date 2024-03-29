#include <CanSatKit.h>

using namespace CanSatKit;


Radio radio(Pins::Radio::ChipSelect,
            Pins::Radio::DIO0,
            433.0,
            Bandwidth_125000_Hz,
            SpreadingFactor_9,
            CodingRate_4_8);

// create (empty) radio frame object that can store data
// to be sent via radio
Frame frame;

void initRadio(){
  radio.begin();
  radio.disable_debug();
}

void transmit(String data){
  frame.print(data);
  radio.transmit(frame);
  frame.clear();
}