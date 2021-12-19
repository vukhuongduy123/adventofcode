#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>

struct coordinate {
    std::pair<int32_t, bool> coor[5][5];
};

std::vector<int32_t> Split(const std::string& s, char delim) {
    std::vector<int32_t> result;
    std::stringstream    ss(s);
    std::string          item;
    while (getline(ss, item, delim)) {
        if (!item.empty())
            result.push_back(stoi(item));
    }

    return result;
}

std::vector<coordinate> GetBoard(std::fstream& input) {
    std::vector<coordinate> board, tmp(1);
    int32_t                 idx = 0, j = 0;
    std::string             num;
    while (getline(input, num)) {
        if (!num.empty()) {
            std::vector<int32_t> vec = Split(num, ' ');
            for (size_t i = 0; i < vec.size(); i++)
                tmp[0].coor[j][i].first = vec[i];
            j++;
            if (j == 5)
                board.push_back(tmp[0]);
        } else {
            j = 0;
            idx++;
        }
    }
    return board;
}

std::vector<int32_t> GetNumber(std::fstream& input) {
    std::vector<int32_t> number;
    std::string          num;
    input >> num;
    number = Split(num, ',');
    return number;
}

bool IsWinnerBoard(coordinate board) {
    bool flag;
    for (int j = 0; j < 5; j++) {
        flag = true;
        for (int m = 0; m < 5; m++) {
            if (!board.coor[j][m].second) {
                flag = false;
                break;
            }
        }
        if (flag)
            return true;
    }
    for (int j = 0; j < 5; j++) {
        flag = true;
        for (int m = 0; m < 5; m++) {
            if (!board.coor[m][j].second) {
                flag = false;
                break;
            }
        }
        if (flag)
            return true;
    }

    return false;
}

int32_t GetScoreBoard(coordinate board, int32_t winner_number) {
    int32_t unmark_number = 0;
    for (int j = 0; j < 5; j++)
        for (int m = 0; m < 5; m++)
            if (!board.coor[j][m].second)
                unmark_number += board.coor[j][m].first;

    return unmark_number * winner_number;
}

int32_t GetLastBoardScore(std::vector<int32_t> number, std::vector<coordinate> board) {
    for (int idx = 0; idx < number.size(); idx++)
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < 5; j++)
                for (int m = 0; m < 5; m++) {
                    if (board[i].coor[j][m].first == number[idx])
                        board[i].coor[j][m].second = true;
                    if (IsWinnerBoard(board[i]))
                        return GetScoreBoard(board[i], number[idx]);
                }

    return 0;
}

int32_t main() {
    std::fstream input;
    // data.txt cotain input taken from
    // https://adventofcode.com/2021/day/4/input
    input.open("data.txt", std::fstream::in);
    std::vector<int32_t>    number = GetNumber(input);
    std::vector<coordinate> board  = GetBoard(input);
    std::cout << GetLastBoardScore(number, board);
}
