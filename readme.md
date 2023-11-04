# Closet Light
An Auto-detection system to turn on or off my closet lighting based on human presence. 
With ability to change colors based on the remote and to activate or deactivate Auto-detection.

## Requirements 
- LED light strip (4 pin - R,G,B, power supply)
- Arduino nano (or ESP32)
- 2N Mosfets * 3
- 1000 ohm resistors * 3
- IR receiver 
- IR remote (  find a remote with a couple of buttons )
- 24v power supply for LED
- 5v power supply for Arduino
- Ultrasonic Sensor Module (you can switch this out and use human motion IR or basic IR)
- Human PIR sensor

## Design

## Usage
Most of the code can be black-boxed if you want to use it. All the pins are defined in `main.ino`. As for the physical remote to modify the colors,  modify codes in the switch cases on `CallRemote()` and `SetColorCodes()`

## License

This project is under the MIT license and may be reused 