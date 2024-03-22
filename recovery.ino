/* #define LANDING_SENSOR_PIN 8 //PIN TO DO
#define BUZZ_PIN 8

bool isWatching=false;

void initRecovery(){
  pinMode(LANDING_SENSOR_PIN, INPUT);
  pinMode(BUZZ_PIN, OUTPUT);
}

void checkAndActivateRecovery(String altitude){
  if(altitude.toFloat()>230){
    isWatching=true;
  }

  bool isOnGround=digitalRead(LANDING_SENSOR_PIN);
  SerialUSB.print(isOnGround);
  if(isOnGround&isWatching){
    play();
  }
}



void beep(uint16_t duration, float hz){
  unsigned long start = millis();
  uint16_t wait = (1000000/hz)/2;

  while(millis()-start<duration){
    digitalWrite(BUZZ_PIN, HIGH);
    delayMicroseconds(wait);
    digitalWrite(BUZZ_PIN, LOW);
    delayMicroseconds(wait);   
  }
}

void noteA(uint16_t time){
  beep(time, 220);
}

void noteE(uint16_t time){
  beep(time, 164.81);
}

void noteB3(uint16_t time){
  beep(time, 246.94);
}

void noteB2(uint16_t time){
  beep(time, 123.47);
}

void noteG(uint16_t time){
  beep(time, 196.00);
}

void noteD(uint16_t time){
  beep(time, 146.83);
}

void noteFis(uint16_t time){
  beep(time, 185.00);
}

void play(){
  noteE(222);
  noteB3(222);
  noteA(222);
  noteG(222);
  noteE(444);
  delay(444);
  noteD(200);
  delay(22);
  noteD(222);
  noteB2(222);
  noteD(222);
  noteE(222);
  delay(666);
  //druga czesc
  noteE(222);
  noteB3(222);
  noteA(222);
  noteG(222);
  noteB3(222);
  noteA(111);
  noteB3(111);
  noteA(222);
  noteG(222);
  noteFis(200);
  delay(22);
  noteFis(111);
  noteG(111);
  noteFis(222);
  noteD(222);
  noteE(222);
} */