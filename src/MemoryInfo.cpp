#include "MemoryInfo.h"
#include <fstream>
#include <iostream>
#include <string>

void MemoryInfo::printMemoryUsage() {
    std::ifstream file("/proc/meminfo");
    std::string key;
    long value;
    std::string unit;

    long total = 0, free = 0, buffers = 0, cached = 0;

    while (file >> key >> value >> unit) {
        if (key == "MemTotal:") total = value;
        else if (key == "MemFree:") free = value;
        else if (key == "Buffers:") buffers = value;
        else if (key == "Cached:") cached = value;
    }

    long used = total - free - buffers - cached;

    std::cout << "Memory Used: "
        << used / 1024 << " MB / "
        << total / 1024 << " MB\n";
}