/*
  An Arduino Library which allows you to communicate seamlessly with u-blox GNSS modules using the Configuration Interface

  SparkFun sells these at its website: www.sparkfun.com
  Do you like this library? Help support SparkFun. Buy a board!
  https://www.sparkfun.com/products/15136
  https://www.sparkfun.com/products/16481
  https://www.sparkfun.com/products/16344
  https://www.sparkfun.com/products/18037
  https://www.sparkfun.com/products/18719
  https://www.sparkfun.com/products/18774
  https://www.sparkfun.com/products/19663
  https://www.sparkfun.com/products/17722

  Original version by Nathan Seidle @ SparkFun Electronics, September 6th, 2018
  v2.0 rework by Paul Clark @ SparkFun Electronics, December 31st, 2020
  v3.0 rework by Paul Clark @ SparkFun Electronics, December 8th, 2022

  https://github.com/sparkfun/SparkFun_u-blox_GNSS_v3

  This library is an updated version of the popular SparkFun u-blox GNSS Arduino Library.
  v3 uses the u-blox Configuration Interface (VALSET and VALGET) to:
  detect the module (during begin); configure message intervals; configure the base location; etc..

  This version of the library will not work with older GNSS modules.
  It is specifically written for newer modules like the ZED-F9P, ZED-F9R and MAX-M10S.
  For older modules, please use v2 of the library: https://github.com/sparkfun/SparkFun_u-blox_GNSS_Arduino_Library

  Development environment specifics:
  Arduino IDE 1.8.19

  SparkFun code, firmware, and software is released under the MIT License(http://opensource.org/licenses/MIT).
  The MIT License (MIT)
  Copyright (c) 2018 SparkFun Electronics
  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
  associated documentation files (the "Software"), to deal in the Software without restriction,
  including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
  and/or sell copies of the Software, and to permit persons to whom the Software is furnished to
  do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all copies or substantial
  portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
  NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

#include "u-blox_GNSS.h"
#include "u-blox_external_typedefs.h"
#include "sfe_bus.h"

class SFE_UBLOX_GNSS : public DevUBLOXGNSS
{
public:
  SFE_UBLOX_GNSS() { _commType = COMM_TYPE_I2C; }

  ///////////////////////////////////////////////////////////////////////
  // begin()
  //
  // This method is called to initialize the SFE_UBLOX_GNSS library and connect to
  // the GNSS device. This method must be called before calling any other method
  // that interacts with the device.
  //
  // Begin will then return true if "signs of life" have been seen: reception of _any_ valid UBX packet or _any_ valid NMEA header.
  //
  // This method follows the standard startup pattern in SparkFun Arduino
  // libraries.
  //
  //  Parameter   Description
  //  ---------   ----------------------------
  //  wirePort    optional. The Wire port. If not provided, the default port is used
  //  address     optional. I2C Address. If not provided, the default address is used.
  //  retval      true on success, false on startup failure
  //
  // This methond is overridden, implementing two versions.
  //
  // Version 1:
  // User skips passing in an I2C object which then defaults to Wire.
  bool begin(i2c_inst_t* i2c_port, uint8_t dev_addr)
  {
    // Setup  I2C object and pass into the superclass
    setCommunicationBus(_i2cBus);

    // Initialize the I2C buss class i.e. setup default Wire port
    _i2cBus.init(i2c_port, dev_addr);

    // Initialize the system - return results
    return this->DevUBLOXGNSS::init(kUBLOXGNSSDefaultMaxWait, false);
  }

private:
  // I2C bus class
  SparkFun_UBLOX_GNSS::SfeI2C _i2cBus;
};
