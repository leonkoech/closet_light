//define pins for the red, green and blue LEDs
#define RED_LED 5
#define BLUE_LED 6
#define GREEN_LED 7

//overall brightness value
int brightness = 255;
//individual brightness values for the red, green and blue LEDs
int gBright = 0; 
int rBright = 0;
int bBright = 0;

int fadeSpeed = 2;

void LedLightSetup(){
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
}

void TurnOn(){
   
    for (int i=0;i<256; i++){
      analogWrite(RED_LED, rBright);
      rBright +=1;
      delay(fadeSpeed);
    }
    
    for (int i=0;i<256; i++){
      analogWrite(BLUE_LED, bBright);
      bBright += 1;
      delay(fadeSpeed);
    }  

    for (int i=0;i<256; i++){
      analogWrite(GREEN_LED, gBright);
      gBright +=1;
      delay(fadeSpeed);
    }  
}

void TurnOff(){
          brightness = 0;
          analogWrite(GREEN_LED, brightness);
          analogWrite(RED_LED, brightness);
          analogWrite(BLUE_LED, brightness); 
}
