#include <fstream>
#include <iostream>
#include <string>
#include <vector>

uint64_t GetFish(std::vector<uint64_t>& fish) {
    for (int idx = 0; idx < 80; idx++) {
        for (int i = 0; i < fish.size(); i++) {
            if (fish[i] > 0)
                fish[i]--;
            else {
                fish[i] = 6;
                fish.push_back(9);
            }
        }
    }
    return fish.size();
}

uint64_t main() {
    std::vector<uint64_t> fish;
    std::string          num;
    std::fstream         input;
    // data.txt cotain input taken from
    // https://adventofcode.com/2021/day/6/input
    input.open("data.txt", std::fstream::in);
    while (getline(input, num, ','))
        fish.push_back(stoi(num));
    std::cout << GetFish(fish);
}