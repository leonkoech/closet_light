#include "ColorStruct.h"
extern bool is_power_on = true;
bool human_presence_motion = false;
unsigned long lastMotionTime = 0;  // Variable to store the time when motion was last detected
const unsigned long motionTimeout = 2000;  // 5 seconds in milliseconds


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
  boolean presence = UltaSonicSensor();
  bool motion = PIRSensor();
  bool is_power = CheckPower();
  
 
//  if motion is detected set human_presence_motion to true
// if presence is not detected set human_presence_motion to false

// use human_presence_motion as the main flag to check
    if (motion) {
    human_presence_motion = true;
    lastMotionTime = millis();  // Reset the timer when motion is detected
  } else if (!presence) {
    human_presence_motion = false;
  }

  // Check the timer
  if (human_presence_motion && is_power) {
    TurnOn();
  } else {
    // Check if the timer has expired (5 seconds)
    if (millis() - lastMotionTime >= motionTimeout) {
      human_presence_motion = false;
      TurnOff();
    }
  }

//  delay(1000);
}
