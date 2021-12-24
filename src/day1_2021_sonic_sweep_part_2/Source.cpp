#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>
uint64_t CountIncreaseMeasurementsWindows(std::vector<uint64_t> sonic_sweep) {
    uint64_t cnt = 0, sum_of_three1, sum_of_three2;
    for (size_t i = 0; i < sonic_sweep.size() - 3; i++) {
        sum_of_three1 =
            sonic_sweep[i] + sonic_sweep[i + 1] + sonic_sweep[i + 2];
        sum_of_three2 =
            sonic_sweep[i + 1] + sonic_sweep[i + 2] + sonic_sweep[i + 3];
        if (sum_of_three2 > sum_of_three1)
            cnt++;
    }

    return cnt;
}

uint64_t main() {
    uint64_t number;
    std::fstream input;
    // data.txt cotain input taken from
    // https://adventofcode.com/2021/day/1/input
    input.open("data.txt", std::fstream::in);
    std::vector<int> sonic_sweep;
    while (input >> number)
        sonic_sweep.push_back(number);
    std::cout << CountIncreaseMeasurementsWindows(sonic_sweep);
}