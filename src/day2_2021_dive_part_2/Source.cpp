#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int32_t GetMultiDepthAndHorizontalPos(
    std::vector<std::pair<std::string, int32_t>> move_command) {
    int32_t depth_pos = 0, horizontal_pos = 0, aim = 0;
    for (size_t i = 0; i < move_command.size(); i++) {
        if (move_command[i].first == "forward") {
            horizontal_pos += move_command[i].second;
            depth_pos += move_command[i].second * aim;
        } else if (move_command[i].first == "down")
            aim += move_command[i].second;
        else if (move_command[i].first == "up")
            aim -= move_command[i].second;
    }
    return depth_pos * horizontal_pos;
}

int main() {
    std::string                                  command;
    int32_t                                      value;
    std::pair<std::string, int32_t>              command_pair;
    std::vector<std::pair<std::string, int32_t>> command_move;
    std::fstream                                 input;
    // data.txt cotain input taken from
    // https://adventofcode.com/2021/day/2/input
    input.open("data.txt", std::fstream::in);
    while (input >> command >> value) {
        command_pair.first  = command;
        command_pair.second = value;
        command_move.push_back(command_pair);
    }
    std::cout << GetMultiDepthAndHorizontalPos(command_move);
}