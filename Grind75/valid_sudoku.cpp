class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Time: O(1), Space: O(1)
        constexpr int SIZE = 9;

        bool rows[SIZE][SIZE], cols[SIZE][SIZE];
        bool squares[SIZE / 3][SIZE / 3][SIZE];

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '.')
                    continue;

                auto num = board[i][j] - '1';

                if(rows[i][num] || cols[j][num] || squares[i / 3][j / 3][num])
                    return false;

                rows[i][num] = true;
                cols[j][num] = true;
                squares[i / 3][j / 3][num] = true;
            }
        }

        return true;
    }
};