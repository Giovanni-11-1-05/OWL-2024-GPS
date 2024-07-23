add_library(max_10 
    sfe_bus.cpp 
    u-blox_GNSS.cpp
    )

target_link_libraries(max_10
    PUBLIC
        pico_stdlib
        pico_time
        hardware_i2c
)
# pull in common dependencies and additional i2c hardware support
target_include_directories(max_10 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(test) # Also include the test subdirectory (which has its own CMakeFile)