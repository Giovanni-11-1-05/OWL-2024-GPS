// Test Program to validate GPS library translation

#include "SparkFun_u-blox_GNSS_v3.h" 

#define KALMAN_3V3_EN_PIN 26

#define KALMAN_I2C_SDA_PIN 28
#define KALMAN_I2C_SCL_PIN 29

#define I2C_CLK_RATE 100000
#define MAX_WAIT 1000

SFE_UBLOX_GNSS gnss_module;

int main() {
    gpio_init(KALMAN_3V3_EN_PIN);
    gpio_set_dir(KALMAN_3V3_EN_PIN, GPIO_OUT);
    gpio_put(KALMAN_3V3_EN_PIN, false);

    stdio_init_all();

    usleep(1000000);//sleeps for 1 second
    
    gpio_put(KALMAN_3V3_EN_PIN, true);

    i2c_inst_t* i2c_port = i2c0; 
    uint8_t dev_addr = 0x42; 

    i2c_init(i2c_port, I2C_CLK_RATE);
    gpio_set_function(KALMAN_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(KALMAN_I2C_SCL_PIN, GPIO_FUNC_I2C);

    gnss_module.begin(i2c_port, dev_addr);

    while(1) {   // Repeatedly fetch coordinates
        // Get current longitude and lattitude
        gnss_module.getPVT();

        int32_t longitude = gnss_module.getLongitude(MAX_WAIT); // maxWait = 1000ms
        int32_t latitude = gnss_module.getLatitude(MAX_WAIT);   // maxWait = 1000ms
        
        int32_t altitude_msl = gnss_module.getAltitudeMSL(MAX_WAIT); // maxWait = 1000ms
        int32_t altitude = gnss_module.getAltitude(MAX_WAIT);        // maxWait = 1000ms

    
        // Convert longitude and latitude to decimal degrees 
        float lon_deg = longitude / 10000000.0;
        float lat_deg = latitude / 10000000.0;

        // Convert altitude to meters
        float altitude_meters_msl = altitude_msl / 1000;
        float altitude_meters = altitude / 1000;

        printf("Latitude: %f, Longitude: %f\n", lat_deg, lon_deg);
        printf("Altitude MSL (m): %f, Altitude (m): %f\n\n", altitude_meters_msl, altitude_meters);
    usleep(1000000);//sleeps for 1 second
    }

    return 0;

}
