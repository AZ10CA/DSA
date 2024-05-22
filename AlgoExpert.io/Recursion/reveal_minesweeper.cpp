#include <vector>

using namespace std;

class Minesweeper {
public:
    vector<vector<string>> board;

    Minesweeper(const vector<vector<string>> &board) {
        this->board = board;
    }

    void click(int i, int j) {
        if (board[i][j] == "M") {
            board[i][j] = "X";
            return;
        }

        // Directions for adjacent cells
        vector<vector<int>> adjacent_cells = {{1,  1},
                                              {1,  -1},
                                              {-1, 1},
                                              {-1, -1},
                                              {0,  1},
                                              {0,  -1},
                                              {-1, 0},
                                              {1,  0}};
        int mine_counter = 0;

        // count mines around the current cell
        for (auto &c: adjacent_cells) {
            int new_i = i + c[0];
            int new_j = j + c[1];
            if (is_valid_cell(new_i, new_j) && board[new_i][new_j] == "M")
                mine_counter++;
        }

        // Set the current cell based on the number of adjacent mines
        if (mine_counter > 0) {
            board[i][j] = std::to_string(mine_counter);
        } else {
            board[i][j] = "0";
            // If no mines are adjacent, recursively reveal adjacent cells
            for (auto &c: adjacent_cells) {
                int new_i = i + c[0];
                int new_j = j + c[1];
                if (is_valid_cell(new_i, new_j) && board[new_i][new_j] == "H")
                    click(new_i, new_j);
            }
        }
    }

    bool is_valid_cell(int i, int j) {
        return i >= 0 && j >= 0 && i < board.size() && j < board[0].size();
    }
};


vector<vector<string>> revealMinesweeper(vector<vector<string>> board, int row, int column) {
    Minesweeper solver(board);
    solver.click(row, column);
    return solver.board;
}