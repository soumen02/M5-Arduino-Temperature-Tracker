# Temperature Tracker
### An M5-Arduino Project

This program is written for Arduino M5ATOM. After compiling the code the device functions as a temperature sensor according to five modes:
- Shows Active temperature + Units (Celsius or Fahrenheit)
- Shows average of last 24 hours of temperature + Units (Celsius or Fahrenheit) 
- Shows color scale of temperature range + current temperature as color 
- Shows graph of temperature across a predefined range. 
- Changes units (Celsius or Fahrenheit)


## Requirements
To run the code download the latest version of Arduino Development Environment. Be sure to install necessary Board resources for the Espressif ESP32 and Libraries for the M5 Atom. 

# Usage 
After compiling the code the device is constantly measuring temperature (every 200 milliseconds). To activate the device press on the button screen. After a red light is displayed on the screen, dynamically tilt the device to left or right (assuming the bottom of the device is where the USB-C port resides). To choose a mode press on the appropriate number displayed on the screen. In mode (v) to change the units, tilt the device and press on the appropriate unit symbol (°C or °F) to choose once. To exit the mode press on the screen. To exit the active display of the device turn the device face-down. 

