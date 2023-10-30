#include "ColorStruct.h"
extern bool is_power_on = true;

void setup() {
  //set up pins to output.
  LedLightSetup();
  RemoteControlSetup();
  UltraSonicSetup();
  AutoDetectSetup();
  SetupRemoteControlMapper();
  //Call the TurnOn method, wait, then call TurnOff
 
}

void loop(){
  AutodetectEventBlinker();
  RemoteControlReceiver();
  float distance = UltaSonicSensor();
  bool presence = detect_human(distance);
  bool is_power = CheckPower();
  Serial.println(distance);
  if(presence && is_power){
        TurnOn();
    }
    else{ 
        TurnOff();
   }

  delayMicroseconds(1000);
}
