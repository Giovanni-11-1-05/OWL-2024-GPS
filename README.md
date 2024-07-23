## GPS Drivers for QuAD RC1

This library adapts the Sparkfun Arduino library for the MAX-M10S 
GNSS module for use with the Raspberry Pi Pico SDK, specifically tailored 
for the RP2040 on the QuAD RC1 board. 


## Software

For developing code for the Pico, it is advisable to establish a Linux development environment. 
If on a Windows machine, VMware is a good option for setting up a virtual machine, from where
a Linux distro can then be installed. Ubuntu is a great, user-friendly choice for getting into Linux. 

* VMWare Workstation Player - https://www.vmware.com/products/workstation-player/workstation-player-evaluation.html.html.html
* Ubuntu - https://ubuntu.com/download/desktop

Be sure to read through this manual for installing the Pico SDK onto your machine:
* Getting started with Raspberry Pi Pico - https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf

It will also be beneficial to setup and install Picotools for quicker loading and flashing of programs onto 
your Pico board. 


## Important Files

Within the QuAD RC1 repository, the GNSS library is located under the `/max_10` directory. Some important files are:

* `sfe_bus.cpp` and `sfe_bus.h`
* `u-blox_GNSS.cpp` and `u-blox_GNSS.h`
* `SparkFun_u-blox_GNSS_v3.h`

~ and several other `u-blox_...` files that have not been modified from their original versions.


## Test Program 

Inside `/max_10/test` there is a test program `max10_lat_long_test.cpp` that initializes I2C and repeatedly
outputs coordinates and altitude data from the GNSS module. 

The test program is simple and can be used as a starting point for other GNSS applications, as it already performs 
the setup process for the GPS module. 

Some important parameters:
```text
Pico SDA PIN:    16
Pico SCL PIN:    17
MAX M10S DEV ADDR: 0x42
```
