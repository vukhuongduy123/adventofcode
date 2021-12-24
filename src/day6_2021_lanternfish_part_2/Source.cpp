#include <fstream>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <numeric>

uint64_t GetFish(std::vector<uint64_t>& fish,const uint64_t days) {
    std::array<uint64_t, 9> fish_count{};
    for (uint64_t i : fish) 
        ++fish_count[i];

    for (int idx = 0; idx < days; idx++) {
        std::rotate(
            fish_count.begin(), fish_count.begin() + 1, fish_count.end());
        fish_count[6] += fish_count[8];
    }

    return std::accumulate(fish_count.begin(),fish_count.end(),0LL);
}

int32_t main() {
    std::vector<uint64_t> fish;
    std::string          num;
    std::fstream         input;
    // data.txt cotain input taken from
    // https://adventofcode.com/2021/day/5/input
    input.open("data.txt", std::fstream::in);
    while (getline(input, num, ','))
        fish.push_back(stoi(num));
    std::cout << GetFish(fish,256);
}