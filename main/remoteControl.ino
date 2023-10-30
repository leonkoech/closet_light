#include <IRremote.hpp> 

#define REMOTE_CODE 15


void RemoteControlSetup(){
//   pinMode(REMOTE_CODE, OUTPUT);
   IrReceiver.begin(REMOTE_CODE, ENABLE_LED_FEEDBACK);
}

void RemoteControlReceiver() {
//    uint16_t command = analogRead(REMOTE_CODE);
   if (IrReceiver.decode()) {
    int command = IrReceiver.decodedIRData.command;
    CallRemote(command);
    IrReceiver.resume();
  }
}
