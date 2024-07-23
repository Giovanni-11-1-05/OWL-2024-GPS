/*
  A Pico Library which allows you to communicate seamlessly with u-blox GNSS modules using the Configuration Interface on a RP2040 MCU

  UART and SPI functions from original Sparkfun libraries have been removed. 
*/


#pragma once

#include "pico.h"
#include "pico/time.h"
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "hardware/structs/i2c.h"
#include <cstring>
#include <stdio.h>

namespace SparkFun_UBLOX_GNSS
{

  class GNSSDeviceBus
  {
  public:
    // Ping the address (I2C specific?)
    virtual bool ping() = 0;

    virtual uint16_t available() = 0;

    // For Serial, do Serial.write
    // For I2C, push data to register 0xFF. Chunkify if necessary. Prevent single byte writes as these are illegal
    virtual uint8_t write_bytes(uint8_t *data, uint8_t length) = 0;
    // For I2C, read from register 0xFF
    virtual uint8_t read_bytes(uint8_t *data, uint8_t length) = 0;
  };

  // The SfeI2C device defines behavior for I2C implementation.
  class SfeI2C : public GNSSDeviceBus
  {
  public:
    void init(i2c_inst_t* i2c_port, uint8_t dev_addr);

    bool ping(); 
    uint16_t available();

    uint8_t write_bytes(uint8_t *data, uint8_t length);
    uint8_t read_bytes(uint8_t *data, uint8_t length);

  private:
    i2c_inst_t* _i2c_port;
    uint8_t _address;
    uint8_t _dev_addr;
  };
};
