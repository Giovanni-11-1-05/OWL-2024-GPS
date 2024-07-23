
add_executable(max10_lat_long_test
    max10_lat_long_test.cpp
)

pico_add_extra_outputs(max10_lat_long_test)
pico_enable_stdio_usb(max10_lat_long_test 1)
pico_enable_stdio_uart(max10_lat_long_test 0)

target_link_libraries(max10_lat_long_test
    PRIVATE
        max_10
        pico_stdlib
        pico_time
        hardware_i2c    
)
