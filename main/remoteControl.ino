#include <IRremote.hpp> 

#define REMOTE_CODE 15

void humanIRSetup(){
   pinMode(REMOTE_CODE, OUTPUT);
   IrReceiver.begin(REMOTE_CODE, ENABLE_LED_FEEDBACK);
}

uint16_t humanIRloop() {\
    uint16_t command = analogRead(REMOTE_CODE);
   if (IrReceiver.decode()) {
    command = IrReceiver.decodedIRData.command;
    Serial.println(command);
    
    IrReceiver.resume();
  }
   return command;
}
