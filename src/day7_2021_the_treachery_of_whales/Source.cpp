#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int32_t GetMedian(const std::vector<int32_t>& crab) {
    return crab.size() % 2
               ? crab[crab.size() / 2]
               : (crab[crab.size() / 2] + crab[crab.size() / 2 - 1]) / 2;
}
int32_t MinFuelMove(std::vector<int32_t>& crab) {
    std::sort(crab.begin(), crab.end());
    int32_t median = GetMedian(crab), sum = 0;

    std::for_each(crab.begin(), crab.end(), [&](int32_t num) {
        sum += std::abs(num - median);
    });
    return sum;
}
int32_t main() {
    std::vector<int32_t> crab;
    std::fstream         input;
    std::string          num;
    // data.txt cotain input taken from
    // https://adventofcode.com/2021/day/5/input
    input.open("data.txt", std::fstream::in);
    while (getline(input, num, ','))
        crab.push_back(stoi(num));
    std::cout << MinFuelMove(crab);
}