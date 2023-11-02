
const int trigger = 16; // OUTPUT to sensor //18
const int echo = 17; // INPUT from sensor //5

// sound speed in cm/ micro second
#define SOUND_SPEED 0.034


long duration;

// function definition (prototype)
bool detect_human(float distance);

void UltraSonicSetup() {

  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

}

boolean UltaSonicSensor() {
  ultrasonic_functioning();
  
  duration = pulseIn(echo, HIGH, 10000); // Set a timeout of 10ms (adjust as needed)
  
  float distance = fetch_distance(duration);
  Serial.println(distance);
  return detect_human(distance);

}

void ultrasonic_functioning(){
  digitalWrite(trigger, LOW);
  delayMicroseconds(20);

  digitalWrite(trigger, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigger, LOW);
}

float fetch_distance(float duration){
  return  duration * SOUND_SPEED/2;
}

boolean detect_human(float distance){
  return distance>1  && distance<100;
}
