#ifndef COLOR_STRUCT_H
#define COLOR_STRUCT_H

struct Color {
    int R;
    int G;
    int B;

    // Constructor-like initialization function
    Color(int red, int green, int blue) : R(red), G(green), B(blue) {}
};

extern Color ColorCollection[16];
extern Color selectedColor;

#endif