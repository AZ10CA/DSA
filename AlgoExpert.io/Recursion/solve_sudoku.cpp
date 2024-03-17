#include <vector>

using namespace std;

class Solver {
    vector<vector<bool>> occupied_rows;
    vector<vector<bool>> occupied_cols;
    vector<vector<vector<bool>>> occupied_squares;
    vector<vector<int>> board;

public:
    vector<vector<vector<int>>> solutions;

public:
    Solver(const vector<vector<int>>& board): board(board){
        occupied_rows = vector<vector<bool>>(9, vector<bool>(9, false));
        occupied_cols = vector<vector<bool>>(9, vector<bool>(9, false));
        occupied_squares = vector<vector<vector<bool>>>(3, vector<vector<bool>>(3, vector<bool>(9, false)));
        pre_process();
    }

    void solve(int i, int j){
        if(j == 9)
            return solve(i + 1, 0);

        if(i == 9) {
            solutions.push_back(board);
            return;
        }

        if(board[i][j] != 0)
            return solve(i, j + 1);

        for(int num = 1; num <= 9; num++){
            if(occupied_rows[i][num - 1] || occupied_cols[j][num - 1] || occupied_squares[i / 3][j / 3][num - 1])
                continue;

            occupied_rows[i][num - 1] = true;
            occupied_cols[j][num - 1] = true;
            occupied_squares[i / 3][j / 3][num - 1] = true;
            board[i][j] = num;

            solve(i, j + 1);

            occupied_rows[i][num - 1] = false;
            occupied_cols[j][num - 1] = false;
            occupied_squares[i / 3][j / 3][num - 1] = false;
            board[i][j] = 0;
        }

    }

    void pre_process(){
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                if(board[i][j] == 0)
                    continue;
                else {
                    occupied_rows[i][board[i][j] - 1] = true;
                    occupied_cols[j][board[i][j] - 1] = true;
                    occupied_squares[i / 3][j / 3][board[i][j] - 1] = true;
                }
    }
};


vector<vector<int>> solveSudoku(vector<vector<int>> board) {
    // Time: O(1), Space: O(1) because size is always 9
    Solver solver(board);
    solver.solve(0, 0);

    return solver.solutions[0];
}