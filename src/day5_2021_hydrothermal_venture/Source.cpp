#include <algorithm>
#include <array>
#include <cctype>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

enum coordinate { x_1, y_1, x_2, y_2 };

struct CoordinateLine {
    uint64_t value[4];
};
struct Coordinate {
    uint64_t value[2];
};

std::vector<CoordinateLine> GetHorAndVerLine(
    const std::vector<CoordinateLine>& vec) {
    std::vector<CoordinateLine> hor_or_ver_line;
    for (int i = 0; i < vec.size(); i++)
        if (vec[i].value[x_1] == vec[i].value[x_2] ||
            vec[i].value[y_1] == vec[i].value[y_2])
            hor_or_ver_line.push_back(vec[i]);
    return hor_or_ver_line;
}
uint64_t GetOverlapPoint(const std::vector<CoordinateLine>& vec) {
    uint64_t                               cnt = 0;
    std::vector<std::array<double, 1000>> point(1000);
    for (uint64_t i = 0; i < vec.size(); i++) {
        if (vec[i].value[y_1] == vec[i].value[y_2]) {
            uint64_t x_min = std::min(vec[i].value[x_1], vec[i].value[x_2]);
            uint64_t x_max = std::max(vec[i].value[x_1], vec[i].value[x_2]);
            for (uint64_t j = x_min; j <= x_max; j++) {
                point[j][vec[i].value[y_1]]++;
                if (point[j][vec[i].value[y_1]] == 2) {
                    cnt++;
                }
            }
        } else {
            uint64_t y_min = std::min(vec[i].value[y_1], vec[i].value[y_2]);
            uint64_t y_max = std::max(vec[i].value[y_1], vec[i].value[y_2]);
            for (uint64_t j = y_min; j <= y_max; j++) {
                point[vec[i].value[x_1]][j]++;
                if (point[vec[i].value[x_1]][j] == 2) {
                    cnt++;
                }
            }
        }
    }
    return cnt;
    
}
uint64_t main() {
    std::string                 line;
    std::fstream                input;
    std::vector<CoordinateLine> vec;
    // data.txt cotain input taken from
    // https://adventofcode.com/2021/day/5/input
    input.open("data.txt", std::fstream::in);
    while (getline(input, line)) {
        uint64_t        idx = 0;
        CoordinateLine coor{};
        for (uint64_t i = 0; i < line.size(); i++) {
            if (std::isdigit(line[i]))
                coor.value[idx] = coor.value[idx] * 10 + (line[i] - '0');
            if ((!std::isdigit(line[i]) && std::isdigit(line[i - 1])) ||
                i == line.size() - 1)
                idx++;
            if (idx == 4)
                vec.push_back(coor);
        }
    }
    std::vector<CoordinateLine> hor_or_ver_line = GetHorAndVerLine(vec);
    std::cout << GetOverlapPoint(hor_or_ver_line);
}