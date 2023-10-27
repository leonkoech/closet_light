
void setup() {
  //set up pins to output.
  LedLightSetup();
  humanIRSetup();
  UltraSonicSetup();
  //Call the TurnOn method, wait, then call TurnOff
 
}

void loop(){
  uint16_t  ir_value = humanIRloop();
  float distance = UltaSonicLoop();
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
