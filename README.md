Any questions you can contact me at gmalone@calpoly.edu
Steps to making the code run.
All non default pi libraries are included within the code I shared. 
Pico.h is to change the pins to the I2C pins of the PI 5. All other functions are commented out if they are needed later.
Files with errors are sfe_bus.h, SparkFun_u-blox_GNSS_v3.h, u-blox_GNSS.cpp, Cmakelists.txt and max10_lat_longtest.cpp.






sfe_bus.h and SparkFun_u-blox_GNSS_v3.h This is due to not knowing what i2c_inst_t does and where it comes from.
Errors in u-blox_GNSS.cpp are from not having the correct time functions. This is hopefully partially solved by importing <chrono> The specific functions that would replace the ones used in u-blox_GNSS.cpp. This library is imported in u-bloc_GNSS.h. I do not understand what the timing functions are doing so I cannot replace it.
Finally in the file that will actually fetch the latitude and longitude is max10_lat_long_test.cpp. All of the GPIO functions should be within lgpio library. https://abyz.me.uk/lg/index.html.
Most of the files should be able to be deleted as they are not relevant to our purpose if we need to trim file size.

Setting up the GPS. I used Pins 3 and 5 for I2C. Pin one for 3V3 power and pin 6 for ground. Wired using the Qwiic connect to breadboard female wires. Blue is SDA, Yellow is SCL, Red is 3V3 (power 3.3V), Black GND.

Pico SDK which is used for the translating the code to the pi 5 https://github.com/raspberrypi/pico-sdk/blob/master/src/host/hardware_timer/include/hardware/timer.h 

![I2C ports](https://cdn.sparkfun.com/assets/learn_tutorials/4/4/9/pin-labels-on-pi-ver2.png)
