

extern bool is_auto = true;
bool is_pin_13_on = true;


unsigned long lastMotionTime = 0;  
const unsigned long motionTimeout = 2000; 

bool human_presence_motion = false;

void AutoDetectSetup(){
   pinMode(LED_BUILTIN, OUTPUT);
}

void AutoDetect(){
  Serial.println("auto clicked");
  is_auto = !is_auto;
}

void ActivateEventBlinker() {
  digitalWrite(LED_BUILTIN, HIGH);
}
void DeActivateEventBlinker() {
   digitalWrite(LED_BUILTIN, LOW);
}

void AutodetectEventBlinker(){
   if(!is_auto){
    if(is_pin_13_on){
        DelayFunction(ActivateEventBlinker, 1000);
    }
    else{
        DelayFunction(DeActivateEventBlinker, 1000);
    }
    is_pin_13_on = !is_pin_13_on;
  }
  else{
     DelayFunction(DeActivateEventBlinker, 1000);
  }
}

void MotionDetector(bool motion, bool presence, bool is_power){
     if (motion) {
      human_presence_motion = true;
      lastMotionTime = millis(); 
    } else if (!motion) {
      Serial.println(presence);
      human_presence_motion = false;
    }

    if (human_presence_motion && is_power) {
      TurnOn();
    } else {
    if (millis() - lastMotionTime >= motionTimeout) {
      human_presence_motion = false;
      TurnOff();
    }
  }
}
