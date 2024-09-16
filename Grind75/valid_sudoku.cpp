class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Time: O(1), Space: O(1)
        constexpr int SIZE = 9;

        vector<bitset<SIZE>> rows(SIZE, bitset<SIZE>()), cols(SIZE, bitset<SIZE>());
        vector<vector<bitset<SIZE>>> square(SIZE / 3,vector<bitset<SIZE>>(SIZE / 3, bitset<SIZE>()));

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '.')
                    continue;

                auto num = board[i][j] - '1';

                if(rows[i][num] || cols[j][num] || square[i / 3][j / 3][num])
                    return false;

                rows[i][num] = true;
                cols[j][num] = true;
                square[i / 3][j / 3][num] = true;
            }
        }

        return true;
    }
};