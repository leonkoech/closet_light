#include "ColorStruct.h"
extern bool is_power_on = true;
bool human_presence_motion = false;


void setup() {
  //set up pins to output.
  LedLightSetup();
  RemoteControlSetup();
  UltraSonicSetup();
  AutoDetectSetup();
  SetupRemoteControlMapper();
  PIRSensorSetup();
  
  Serial.begin(115200);
 
}

void loop(){
//  AutodetectEventBlinker();
  RemoteControlReceiver();
  bool presence = UltaSonicSensor();
  bool motion = PIRSensor();
  bool is_power = CheckPower();

// motion detection function that sets the lights on or off based on presence, motion and whether power has been activated or not
  MotionDetector(motion, presence, is_power);
 
 
}
