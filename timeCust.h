#ifndef TIMECUST_H
#define TIMECUST_H


#include<iostream>
#include <chrono>
#include <unistd.h>
#include <typeinfo>
#include <string>

using namespace std;
using namespace chrono;

uint64_t ttime = 0;
high_resolution_clock::time_point t1 = high_resolution_clock::now();



int timeSinceBoot( ){
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    auto tm_duration = duration_cast<microseconds>(t2 - t1).count();
    uint32_t ttimeMilli = tm_duration/1000; //converts to milliseconds
    //cout << "Took " << ttimeMilli << " microseconds " << endl;
    return ttimeMilli;
}

#endif