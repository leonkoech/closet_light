#define OUTPUT_PIN 9

int state = LOW;
int val  = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(OUTPUT_PIN, INPUT);

}

void loop() {
   val = digitalRead(OUTPUT_PIN);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
//    digitalWrite(led, HIGH);   // turn LED ON
    delay(100);                // delay 100 milliseconds 
    
    if (state == LOW) {
      Serial.println("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {
//      digitalWrite(led, LOW); // turn LED OFF
      delay(200);             // delay 200 milliseconds 
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }

}
