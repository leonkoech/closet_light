
#define AUTODETECT_ACTIVE_PIN 13
bool is_auto = true;

void SetAutoDetect(){
  is_auto = !is_auto;
}

void ActivateEventBlinker() {
  digitalWrite(AUTODETECT_ACTIVE_PIN, LOW);
}
void DeActivateEventBlinker() {
   digitalWrite(AUTODETECT_ACTIVE_PIN, HIGH);
}

void AutodetectEventBlinker(){
   if(is_auto){
    bool is_on = true;
    if(is_on){
        DelayFunction(ActivateEventBlinker, 1000);
    }
    else{
        DelayFunction(DeActivateEventBlinker, 1000);
    }
    is_on = !is_on;
  }
  else{
     DelayFunction(DeActivateEventBlinker, 1000);
  }
}
