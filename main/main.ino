#include "ColorStruct.h"

// define pins for the Ultrasonic sensor
#define TRIGGER 16 
#define ECHO  17
// define pin for the PIR motion detector
#define PIR 19
// define pin for the autodetection led pin
#define AUTODETECT_ACTIVE_PIN 13
//define pins for the red, green and blue LEDs
#define RED_LED 6
#define BLUE_LED 7
#define GREEN_LED 5

// define min distance and max distance for the Ultrasonic detector
#define MIN_DISTANCE 2
#define MAX_DISTANCE 100

extern bool is_power_on = true;


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
  AutodetectEventBlinker();
  RemoteControlReceiver();
  boolean presence = UltaSonicSensor(MIN_DISTANCE, MAX_DISTANCE);
  bool motion = PIRSensor();
  bool is_power = CheckPower();

  MotionDetector(motion, presence, is_power);
 
}
