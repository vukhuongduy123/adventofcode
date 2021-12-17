#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>
int32_t CountIncreaseMeasurements(std::vector<int32_t> sonic_sweep) {
    int32_t cnt = 0;
    for (size_t i = 0; i < sonic_sweep.size() - 1; i++)
        if (sonic_sweep[i + 1] > sonic_sweep[i])
            cnt++;
    return cnt;
}

int32_t main() {
    int32_t      number;
    std::fstream input;
    input.open("data.txt", std::fstream::in);
    std::vector<int> sonic_sweep;
    while (input >> number)
        sonic_sweep.push_back(number);
    std::cout << CountIncreaseMeasurements(sonic_sweep);
}