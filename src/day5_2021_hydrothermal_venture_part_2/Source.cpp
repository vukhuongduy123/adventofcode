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
    int32_t value[4];
};
struct Coordinate {
    int32_t value[2];
};

int32_t GetOverlapPoint(const std::vector<CoordinateLine>& vec) {
    int32_t                               cnt = 0;
    std::vector<std::array<double, 1000>> point(1000);
    for (int32_t i = 0; i < vec.size(); i++) {
        if (vec[i].value[y_1] == vec[i].value[y_2]) {
            int32_t x_min = std::min(vec[i].value[x_1], vec[i].value[x_2]);
            int32_t x_max = std::max(vec[i].value[x_1], vec[i].value[x_2]);
            for (int32_t j = x_min; j <= x_max; j++) {
                point[j][vec[i].value[y_1]]++;
                if (point[j][vec[i].value[y_1]] == 2)
                    cnt++;
            }
        } else if (vec[i].value[x_1] == vec[i].value[x_2]) {
            int32_t y_min = std::min(vec[i].value[y_1], vec[i].value[y_2]);
            int32_t y_max = std::max(vec[i].value[y_1], vec[i].value[y_2]);
            for (int32_t j = y_min; j <= y_max; j++) {
                point[vec[i].value[x_1]][j]++;
                if (point[vec[i].value[x_1]][j] == 2)
                    cnt++;
            }
        } else {
            int32_t distance1 = vec[i].value[x_1] - vec[i].value[x_2];
            int32_t distance2 = vec[i].value[y_1] - vec[i].value[y_2];
            distance1 /= std::abs(distance1);
            distance2 /= std::abs(distance2);
            for (int32_t m = vec[i].value[x_1], j = vec[i].value[y_1];
                 m != vec[i].value[x_2] && j != vec[i].value[y_2];
                 m -= distance1, j -= distance2) {
                point[m][j]++;
                if (point[m][j] == 2)
                    cnt++;
            }
            //get the last point since point come from x_1,y_1 to x_2,y_2
            point[vec[i].value[x_2]][vec[i].value[y_2]]++;
            if (point[vec[i].value[x_2]][vec[i].value[y_2]] == 2)
                cnt++;
        }
    }
    return cnt;
}
int32_t main() {
    std::string                 line;
    std::fstream                input;
    std::vector<CoordinateLine> vec;
    // data.txt cotain input taken from
    // https://adventofcode.com/2021/day/5/input
    input.open("data.txt", std::fstream::in);
    while (getline(input, line)) {
        int32_t        idx = 0;
        CoordinateLine coor{};
        for (int32_t i = 0; i < line.size(); i++) {
            if (std::isdigit(line[i]))
                coor.value[idx] = coor.value[idx] * 10 + (line[i] - '0');
            if ((!std::isdigit(line[i]) && std::isdigit(line[i - 1])) ||
                i == line.size() - 1)
                idx++;
            if (idx == 4)
                vec.push_back(coor);
        }
    }
    std::cout << GetOverlapPoint(vec);
}