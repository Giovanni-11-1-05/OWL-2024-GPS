/*
  A library which allows you to communicate seamlessly with u-blox GNSS modules using the Configuration Interface
  written for the Pico SDK and RP2040 MCU. 

  UART and SPI functions from original Sparkfun library have been removed. 

*/

#include "sfe_bus.h"

namespace SparkFun_UBLOX_GNSS
{

  void SfeI2C::init(i2c_inst_t* i2c_port, uint8_t dev_addr) 
  {
    _i2c_port = i2c_port; // Assign I2C port to member variable
    _dev_addr = dev_addr; // Store I2C address
  }

  //////////////////////////////////////////////////////////////////////////////////////////////////
  // ping()
  //
  // Is a device connected?
  bool SfeI2C::ping()
  {
    uint8_t test_byte = 0x00; 
    // Attempt to write a byte 
    int result = i2c_write_blocking(_i2c_port, _dev_addr, &test_byte, 1, false);
    // If result is 1, byte was written successfully! 
    return result == 1;
  }

  //////////////////////////////////////////////////////////////////////////////////////////////////
  // available()
  //
  // Checks how many bytes are waiting in the GNSS's I2C buffer
  // It does this by reading registers 0xFD and 0xFE

  uint16_t SfeI2C::available()
  {
      uint8_t BYTES_AVAIL_MSB_ADDR = 0xFD;
      uint8_t avail_buff[2];
      int write_ret = i2c_write_blocking(i2c0, _dev_addr, &BYTES_AVAIL_MSB_ADDR, 1, true);
      int read_ret = i2c_read_blocking(i2c0, _dev_addr, avail_buff, 2, false);
      if(write_ret > 0 && read_ret > 0)
          return (avail_buff[0] << 8) | avail_buff[1];
      else
          return 0;
  }

  //////////////////////////////////////////////////////////////////////////////////////////////////
  // write_bytes()

  uint8_t SfeI2C::write_bytes(uint8_t *data, uint8_t length)
  {    
    // Perform I2C write operation
    int result = i2c_write_blocking(_i2c_port, _dev_addr, data, length, false);

    // Check result length. If the length of written byte = length, return length (success!)
    if (result == length) {
      return result; 
    }
    else {
        return 0; // Write failure
    }
  }

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // read_bytes()

  uint8_t SfeI2C::read_bytes(uint8_t *data, uint8_t length)
  {
    // Perform I2C read operation
    int result = i2c_read_blocking(_i2c_port, _dev_addr, data, length, false);

    // Check result length. If the length of read byte = length, return length (success!)
    if (result == length) {  
        return result; 
    }
    else {
        return 0; // Read failure   
    }
  }
}

 