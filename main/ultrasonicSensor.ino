


// sound speed in cm/ micro second
#define SOUND_SPEED 0.034


long duration;

// function definition (prototype)
bool detect_human(float distance);

void UltraSonicSetup() {

  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);

}

boolean UltaSonicSensor(float min_distance, float max_distance) {
  ultrasonic_functioning();
  
  duration = pulseIn(ECHO, HIGH, 10000); // Set a timeout of 10ms (adjust as needed)
  
  float current_distance = fetch_distance(duration);
  Serial.println(current_distance);
  return detect_human(current_distance, min_distance, max_distance);

}

void ultrasonic_functioning(){
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(20);

  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(20);
  digitalWrite(TRIGGER, LOW);
}

float fetch_distance(float duration){
  return  duration * SOUND_SPEED/2;
}

boolean detect_human(float distance, float min_distance, float max_distance){
  return distance>min_distance  && distance<max_distance;
}
