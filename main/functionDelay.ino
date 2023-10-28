unsigned long previousMillis = 0;
template <typename T>

void DelayFunction(T parameterFunction, unsigned long delayInterval) {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= delayInterval) {
    parameterFunction();
    previousMillis = currentMillis;
  }
}
