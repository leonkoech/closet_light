#include <IRremote.hpp> 

#define REMOTE_CODE 15


void RemoteControlSetup(){
   pinMode(REMOTE_CODE, OUTPUT);
   pinMode(AUTODETECT_ACTIVE_PIN, OUTPUT);
   IrReceiver.begin(REMOTE_CODE, ENABLE_LED_FEEDBACK);
}

uint16_t RemoteControlReceiver() {
    uint16_t command = analogRead(REMOTE_CODE);
   if (IrReceiver.decode()) {
    command = IrReceiver.decodedIRData.command;
    Serial.println(command);
    IrReceiver.resume();
  }
   return command;
}
