
const int trigger = 16; // OUTPUT to sensor //18
const int echo = 17; // INPUT from sensor //5

// sound speed in cm/ micro second
#define SOUND_SPEED 0.034


long duration;

// function definition (prototype)
bool check_distance(float distance);

void UlltaSonicSetup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
//  pinMode(vibration, OUTPUT);

}

float UltaSonicLoop() {
  
  ultrasonic_functioning();
  
  duration = pulseIn(echo, HIGH);
  
  return fetch_distance(duration);
}

void ultrasonic_functioning(){
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);

  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
}

float fetch_distance(float duration){
  return  duration * SOUND_SPEED/2;
}

boolean detect_human(float distance){
  return distance>2 && distance<100;
}
