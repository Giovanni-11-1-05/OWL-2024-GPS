Any questions you can contact me at gmalone@calpoly.edu
Steps to making the code run.
All non default pi libraries are included within the code I shared. 
Pico.h is to change the pins to the I2C pins of the PI 5. All other functions are commented out if they are needed later.
Files with errors are sfe_bus.h, SparkFun_u-blox_GNSS_v3.h, u-blox_GNSS.cpp, Cmakelists.txt and max10_lat_longtest.cpp.
sfe_bus.h and SparkFun_ublox_GNSS_v3.h where i2c_inst_t is undefined. This is because these were from the old Pico SDK libraries.
The included libraries that used to be used were "hardware/i2c.h" and "hardware/structs/i2c.h".
The errors for u-blox_GNSS.cpp are from type assignment errors. I have no idea what these are from.
CMakeLists.txt has errors prom having pico commands still in it I have not had the time to try and fix it.
max10_lat_long_test.cpp errors are from the gpio initialization. The fix for this will depend on the implementation of i2c.
I have already added the lgpio library but I have not been able to figure out what the current i2c commands are doing so I do not know how to replace them.

Setting up the GPS. I used Pins 3 and 5 for I2C. Pin one for 3V3 power and pin 6 for ground. Wired using the Qwiic connect to breadboard female wires. Blue is SDA, Yellow is SCL, Red is 3V3 (power 3.3V), Black GND.

Pico SDK which is used for the translating the code to the pi 5 https://github.com/raspberrypi/pico-sdk/blob/master/src/host/hardware_timer/include/hardware/timer.h 

![I2C ports](https://cdn.sparkfun.com/assets/learn_tutorials/4/4/9/pin-labels-on-pi-ver2.png)
