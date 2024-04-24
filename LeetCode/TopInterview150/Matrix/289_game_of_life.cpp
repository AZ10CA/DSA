class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // Time: O(nm), Space: O(nm)
        vector<vector<int>> neighbors_count(board.size(), vector<int>(board[0].size(), 0));

        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++)
                neighbors_count[i][j] = count_live_neighbors(board, i, j);

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                auto cell = neighbors_count[i][j];
                auto& board_cell = board[i][j];
                if(board[i][j] == 1){
                    if(cell < 2)
                        board_cell = 0;
                    else if(cell <= 3)
                        continue;
                    else if(cell > 3)
                        board_cell = 0;
                } else {
                    if(cell == 3)
                        board_cell = 1;
                }
            }
        }
    }

    int count_live_neighbors(const vector<vector<int>>& board, int i, int j){
        static vector<pair<int, int>> directions = {{-1, -1}, {-1, 1}, {-1, 0}, {1, 0}, {1, 1}, {1, -1}, {0, 1}, {0, -1}};
        auto cnt = 0;

        for(auto &[x, y]: directions){
            auto new_i = i + x;
            auto new_j = j + y;
            if(new_i >= 0 && new_i < board.size() && new_j >= 0 && new_j < board[i].size() && board[new_i][new_j] == 1)
                cnt++;
        }

        return cnt;
    }
};