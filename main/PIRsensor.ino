#define OUTPUT_PIN 19

int human_pir_detected  = 0;

void PIRSensorSetup() {
  pinMode(OUTPUT_PIN, INPUT);

}

boolean PIRSensor() {
   human_pir_detected = digitalRead(OUTPUT_PIN);
   Serial.println(human_pir_detected == HIGH?"motion":"motion ended");
   return human_pir_detected == HIGH;

}
