
#include "ColorStruct.h"

  Color red(255, 0, 0);
  Color green(0, 255, 0);
  Color blue(0, 0, 255);
  Color white(255, 255, 255);
  
  Color secRed(255, 88, 46);
  Color secGreen(46, 255, 60);
  Color secBlue(0, 102, 204);
  
  Color orange(255, 128, 0);
  Color sky(0, 255, 255);
  Color purple(127, 0, 255);
  
  Color secOrange(255, 178, 102);
  Color secSky(0, 153, 153);
  Color secPurple(76, 0, 103);
  
  Color yellow(255, 255, 0);
  Color midnightGreen(0, 153, 76);
  Color pink(255, 0, 127);


 Color ColorCollection[] = {
    red, green, blue, white, secRed, secGreen, secBlue, orange,
    sky, purple, secOrange, secSky, secPurple, yellow, midnightGreen, pink
};
  
void SetColorCodes(){
    ColorCollection[88] = red;
    ColorCollection[89] = green;
    ColorCollection[69] = blue;
    ColorCollection[68] = white;
    ColorCollection[84] = secRed;
    ColorCollection[85] = secGreen;
    ColorCollection[73] = secBlue;
    ColorCollection[80] = orange;
    ColorCollection[81] = sky;
    ColorCollection[77] = purple;
    ColorCollection[28] = secOrange;
    ColorCollection[29] = secSky;
    ColorCollection[30] = secPurple;
    ColorCollection[24] = yellow;
    ColorCollection[25] = midnightGreen;
    ColorCollection[26] = pink;
}

Color selectedColor = red;

void SetColor(int code){
  selectedColor = ColorCollection[code];
}
