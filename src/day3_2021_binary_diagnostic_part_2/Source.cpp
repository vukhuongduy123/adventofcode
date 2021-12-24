#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

uint64_t GetLifeSupportRating(std::vector<std::string> number) {
    uint64_t                  idx  = 0;
    std::vector<std::string> copy = number;
    while (number.size() > 1) {
        auto pos = std::partition(
            number.begin(), number.end(), [idx](const std::string& s) {
                return s[idx] != '0';
            });
        if (pos - number.begin() >= number.end() -pos)
            number.erase(pos, number.end());
        else
            number.erase(number.begin(), pos);
        idx++;
    }
    idx = 0;
    while (copy.size() > 1) {
        auto pos = std::partition(
            copy.begin(), copy.end(), [idx](const std::string& s) {
                return s[idx] != '0';
            });
        if (pos - copy.begin() >= copy.end() - pos)
            copy.erase(copy.begin(), pos);
        else
            copy.erase(pos, copy.end());
        idx++;
    }
    return stoi(number[0], nullptr, 2) * stoi(copy[0], nullptr, 2);
}

uint64_t main() {
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