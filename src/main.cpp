#include <iostream>
#include <thread>
#include <chrono>

#include "MemoryInfo.h"

int main(){
    MemoryInfo memory;

    while (true) {
        memory.printMemoryUsage();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}