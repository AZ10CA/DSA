class Solution {
    vector<vector<bool>> rows;
    vector<vector<bool>> cols;
    vector<vector<vector<bool>>> squares;

    vector<vector<char>> board, solution;

public:
    Solution() : rows(9, vector<bool>(10, false)), cols(9, vector<bool>(10, false)), squares(3, vector<vector<bool>>(3, vector<bool>(10, false))) {}

    void update_states(){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                auto value = board[i][j];
                if(value == '.')
                    continue;
                auto digit = value - '0';
                rows[i][digit] = true;
                cols[j][digit] = true;
                squares[i / 3][j / 3][digit] = true;
            }
        }
    }

    void solve(int i, int j){
        if(i == board.size()){
            solution = board;
            return;
        }

        if(j == board[i].size())
            return solve(i + 1, 0);

        if(board[i][j] != '.')
            return solve(i, j + 1);

        for(int c = 1; c < 10; c++){
            if(board[i][j] != '.' || squares[i / 3][j / 3][c] || rows[i][c] || cols[j][c])
                continue;

            rows[i][c] = cols[j][c] = squares[i / 3][j / 3][c] = true;
            board[i][j] = c + '0';

            solve(i, j + 1);

            board[i][j] = '.';
            rows[i][c] = cols[j][c] = squares[i / 3][j / 3][c] = false;
        }
    }


    void solveSudoku(vector<vector<char>>& b) {
        board = b;
        update_states();
        solve(0, 0);
        b = solution;
    }
};