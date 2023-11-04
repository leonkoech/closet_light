

int human_pir_detected  = 0;

void PIRSensorSetup() {
  pinMode(PIR, INPUT);

}

boolean PIRSensor() {
   human_pir_detected = digitalRead(PIR);
   Serial.println(human_pir_detected == HIGH?"motion":"motion ended");
   return human_pir_detected == HIGH;

}
