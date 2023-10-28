
void setup() {
  //set up pins to output.
  LedLightSetup();
  RemoteControlSetup();
  UltraSonicSetup();
  //Call the TurnOn method, wait, then call TurnOff
 
}

void loop(){
  AutodetectEventBlinker();
  uint16_t  ir_value = RemoteControlReceiver();
  float distance = UltaSonicSensor();
  boolean presence = detect_human(distance);
  Serial.println(ir_value);
//  Serial.println(distance);
//  Serial.println(presence);
  if(presence){
      TurnOn();
  }
  else{ 
      TurnOff();
  }
  
  delayMicroseconds(10);
}
