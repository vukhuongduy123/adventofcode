#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int32_t MinFuelMove(const std::vector<int32_t>& crab) {
    int32_t average1 =
        std::accumulate(crab.begin(), crab.end(), 0.0) / crab.size();
    int32_t average2 = average1 + 1;
    int32_t sum1 = 0,sum2=0;
    for (int32_t idx = 0; idx < crab.size(); idx++) {
        sum1 += std::abs(crab[idx] - average1) *
               (1 + std::abs(crab[idx] - average1)) / 2;
        sum2 += std::abs(crab[idx] - average2) *
                (1 + std::abs(crab[idx] - average2)) / 2;

    }
    return std::min(sum1,sum2);
}
int32_t main() {
    std::vector<int32_t> crab;
    std::fstream         input;
    std::string          num;
    // data.txt cotain input taken from
    // https://adventofcode.com/2021/day/7/input
    input.open("data.txt", std::fstream::in);
    while (getline(input, num, ','))
        crab.push_back(stoi(num));
    std::cout << MinFuelMove(crab);
}