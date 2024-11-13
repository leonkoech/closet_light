# Closet Light

## Auto-Detection Lighting System with Remote Control and Color Customization

The **Closet Light** system is an automated lighting solution designed to detect human presence and activate or deactivate the lights accordingly. The system integrates a PIR sensor (or alternative motion detection technology) to sense movement, an IR receiver for remote control, and a microcontroller (Arduino Nano or ESP32) to manage light color changes and auto-detection activation. The system allows users to modify light colors and enable/disable motion detection using the IR remote.


![IMG_0033](https://github.com/user-attachments/assets/f6906af8-8fc8-4767-9812-ef969ffe7aa4)


## Project Requirements

### Hardware Components

- **LED Light Strip (4-pin: R, G, B, power supply)**  
  RGB LED strip capable of color customization.
  
- **Arduino Nano (or ESP32)**  
  Microcontroller for handling logic, sensor readings, and IR remote communication.

- **2N Mosfets (x3)**  
  Used to control the power to each of the R, G, B pins of the LED light strip.

- **1000 Ohm Resistors (x3)**  
  Current-limiting resistors for the Mosfets to prevent overload.

- **IR Receiver**  
  Receives commands from the IR remote.

- **IR Remote**  
  A remote control with at least a few buttons for changing light colors and activating/deactivating auto-detection.

- **24V Power Supply for LED**  
  Provides power to the LED light strip.

- **5V Power Supply for Arduino**  
  Powers the Arduino or ESP32 board.

- **Ultrasonic Sensor Module (or Human PIR Sensor)**  
  Optional: Use of ultrasonic sensor for proximity sensing or replace with a PIR sensor for motion detection.



## System Design

The **Closet Light** system is designed to function with two main operating modes: **Auto-detection mode** and **Manual control mode**. The primary components of the system are as follows:

1. **PIR Sensor**: Detects human presence and sends a signal to the Arduino to turn the lights on or off.
   
2. **IR Remote**: Allows the user to change the color of the LED lights remotely. The system listens for commands from the remote to adjust the light color or toggle the auto-detection mode.

3. **LED Strip**: A 4-pin RGB LED strip is connected to the Arduino via 2N Mosfets. These Mosfets allow the Arduino to control the brightness and color of the LEDs.

4. **Mosfets**: Control the flow of current to the LED strip, enabling or disabling colors based on the user’s input or detected motion.

5. **Microcontroller (Arduino or ESP32)**: Handles the logic for light control, sensor readings, and IR communication.


## Usage Instructions

1. **System Setup**:  
   All the wiring connections are mapped out in the `main.ino` file. The pins for the PIR sensor, IR receiver, and LED strip are defined within the code. Ensure that all components are connected according to the wiring diagram provided.

2. **Color Customization**:  
   To modify the colors of the LED strip via the IR remote, locate the `CallRemote()` and `SetColorCodes()` functions in the `main.ino` file. These functions handle the logic for changing the colors when specific buttons on the remote are pressed. Customize the color values in the switch cases within these functions as needed.

3. **Activating Auto-Detection**:  
   The auto-detection mode uses the PIR sensor (or ultrasonic sensor) to automatically turn the lights on when motion is detected and off after a set duration of no motion. This feature can be toggled via the IR remote by setting the relevant button in the remote handler code.

4. **Manual Control**:  
   Use the remote to manually toggle between different lighting colors. The IR remote should provide buttons for switching between at least 3 different colors, with the option to turn off the lights completely.


## License

This project is released under the [MIT License](https://opensource.org/licenses/MIT). It is free to use, modify, and distribute with proper attribution.

