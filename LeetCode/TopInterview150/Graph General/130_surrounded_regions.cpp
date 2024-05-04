class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // Time: O(n^2), Space: O(1)
        int rows = board.size();
        int cols = board[0].size();

        for(int i = 0; i < cols; i++){
            dfs(0, i, board);
            dfs(rows - 1, i, board);
        }

        for(int j = 0; j < rows; j++){
            dfs(j, 0, board);
            dfs(j, cols - 1, board);
        }

        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] != 'T')
                    board[i][j] = 'X';
                else board[i][j] = 'O';
            }
    }

    void dfs(int i, int j, vector<vector<char>>& board){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return;

        if(board[i][j] != 'O')
            return;

        board[i][j] = 'T';
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for(auto &[x, y]: directions){
            auto new_x = x + i;
            auto new_y = y + j;
            dfs(new_x, new_y, board);
        }
    }
};