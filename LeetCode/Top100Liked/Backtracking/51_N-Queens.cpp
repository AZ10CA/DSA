#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>

using namespace std;

class Board {
private:
    int sz;
    vector<vector<bool>> board;
    vector<pair<int, int>> occupied_positions;
    unordered_set<int> occupied_cols;

public:
    [[nodiscard]] int size() const {
        return sz;
    }

    explicit Board(int size) : sz(size) {
        board = vector<vector<bool >>(size, vector<bool>(size, false));
    }


    void occupy(int i, int j) { // put a queen
        board[i][j] = true;
        occupied_positions.emplace_back(i, j);
        occupied_cols.insert(j);
    }

    void vacate(int i, int j) {
        board[i][j] = false;
        assert(occupied_positions[occupied_positions.size() - 1] == make_pair(i, j));
        occupied_positions.pop_back();
        occupied_cols.erase(j);
    }

private:
    static bool is_same_row(const std::pair<int, int> &first, const std::pair<int, int> &second) {
        return first.first == second.first;
    }

    static bool is_same_col(const std::pair<int, int> &first, const std::pair<int, int> &second) {
        return first.second == second.second;
    }

    static bool is_same_diagonal(const std::pair<int, int> &first, const std::pair<int, int> &second) {
        return std::abs(first.first - second.first) == std::abs(first.second - second.second);
    }

public:
    [[nodiscard]] int queen_count() const {
        return int(occupied_positions.size());
    }

    vector<string> convert_board() {
        vector<string> result;
        for (int i = 0; i < sz; i++) {
            string row;
            for (int j = 0; j < sz; j++)
                row += board[i][j] == 1 ? 'Q' : '.';
            result.push_back(row);
        }

        return result;
    }

    bool is_available(int i, int j) {
        if (occupied_cols.find(j) != occupied_cols.end())
            return false;
        for (auto pos: occupied_positions) {
            auto needed = make_pair(i, j);
            if (is_same_diagonal(needed, pos))
                return false;
        }

        return true;
    }

    bool is_col_available(int j) {
        return occupied_cols.find(j) == occupied_cols.end();
    }
};


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        Board board(n);
        generate(0, board, result);
        return result;
    }

    void generate(int i, Board &board, vector<vector<string>> &result) {
        if (board.queen_count() == board.size()) {
            result.push_back(board.convert_board());
            return;
        }
        for (int z = 0; z < board.size(); z++) {
            if (board.is_available(i, z)) {
                board.occupy(i, z);
                generate(i + 1, board, result);
                board.vacate(i, z);
            }
        }
    }
};
