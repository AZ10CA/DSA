class Solution {
    vector<vector<bool>> visited;
public:
    bool exist(vector<vector<char>>& board, string word) {
        // Time: O(nm4^l), Space: O(nm)
        visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));

        bool result = false;
        for(int i = 0; i < board.size() && not result; i++)
            for(int j = 0; j < board[i].size() && not result; j++)
                result |= traverse(i, j, 0, board, word);

        return result;
    }

    bool traverse(int i, int j, int idx, const vector<vector<char>>& board, string word){
        if(idx == word.size())
            return true;

        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j] || board[i][j] != word[idx])
            return false;

        visited[i][j] = true;
        auto result = traverse(i + 1, j, idx + 1, board, word) ||
                      traverse(i, j + 1, idx + 1, board, word) ||
                      traverse(i - 1, j, idx + 1, board, word) ||
                      traverse(i, j - 1, idx + 1, board, word);
        visited[i][j] = false;

        return result;
    }
};