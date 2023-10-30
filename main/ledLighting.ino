//define pins for the red, green and blue LEDs
#define RED_LED 6
#define BLUE_LED 7
#define GREEN_LED 5


void LedLightSetup(){
  SetColorCodes();
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
}

void getColor(){
    analogWrite(RED_LED, selectedColor.R);
    analogWrite(BLUE_LED, selectedColor.B);
    analogWrite(GREEN_LED, selectedColor.G);
}

void TurnOn(){
    getColor();
}

void TurnOff(){
          int brightness = 0;
          analogWrite(GREEN_LED, brightness);
          analogWrite(RED_LED, brightness);
          analogWrite(BLUE_LED, brightness); 
}
