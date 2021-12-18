#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int32_t GetLifeSupportRating(std::vector<std::string> number) {
    std::string res;
    for (size_t i = 0; i < number[0].size(); i++) {
        std::partition(number.begin(), number.end(), [i](const std::string& s) {
            return s[i] != '0';
        });
        res += number[number.size() / 2][i];
    }
    uint32_t gamma   = std::stoi(res, nullptr, 2);
    uint32_t epsilon = ~gamma;
    epsilon <<= (32 - number[0].size());
    epsilon >>= (32 - number[0].size());
    return gamma * epsilon;
}

int32_t main() {
    std::vector<std::string> number;
    std::string              num;
    std::fstream             input;
    // data.txt cotain input taken from
    // https://adventofcode.com/2021/day/3/input
    input.open("data.txt", std::fstream::in);
    while (input >> num)
        number.push_back(num);
    std::cout << GetLifeSupportRating(number);
}