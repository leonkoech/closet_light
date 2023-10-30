
#define AUTODETECT_ACTIVE_PIN 13
extern bool is_auto = true;
bool is_pin_13_on = true;

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
