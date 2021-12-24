#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>
uint64_t CountIncreaseMeasurements(std::vector<uint64_t> sonic_sweep) {
    uint64_t cnt = 0;
    for (size_t i = 0; i < sonic_sweep.size() - 1; i++)
        if (sonic_sweep[i + 1] > sonic_sweep[i])
            cnt++;
    return cnt;
}

uint64_t main() {
    uint64_t      number;
    std::fstream input;
    //data.txt cotain input taken from https://adventofcode.com/2021/day/1/input
    input.open("data.txt", std::fstream::in);
    std::vector<uint64_t> sonic_sweep;
    while (input >> number)
        sonic_sweep.push_back(number);
    std::cout << CountIncreaseMeasurements(sonic_sweep);
}