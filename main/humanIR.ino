#include <IRremote.hpp> 

const int human_sensor = A0;

void humanIRSetup(){
   pinMode(human_sensor, OUTPUT);
   IrReceiver.begin(human_sensor, ENABLE_LED_FEEDBACK);
}

int humanIRloop() {
   if (IrReceiver.decode()) {
    uint16_t command = IrReceiver.decodedIRData.command;
//    Serial.println(command);
    
    IrReceiver.resume();
  }
   return analogRead(human_sensor);
}
