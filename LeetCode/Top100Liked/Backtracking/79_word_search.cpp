class Solution {
public:
    vector<pair<int, int>> directions = {{1,  0},
                                         {0,  1},
                                         {0,  -1},
                                         {-1, 0}};

    bool exist(vector<vector<char>> &board, string word) {
        // Time: O(m * n * w)
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        auto result = false;
        for (int i = 0; i < board.size() && !result; i++) {
            for (int j = 0; j < board[0].size() && !result; j++) {
                result |= search(0, word, i, j, board, visited);
            }
        }
        return result;
    }

    bool search(int idx, const string &word, int i, int j, const vector<vector<char>> &board,
                vector<vector<bool>> &visited) {
        if (idx == word.size())
            return true;

        if (i >= board.size() || j >= board[0].size() || i < 0 || j < 0)
            return false;

        if (visited[i][j])
            return false;

        visited[i][j] = true;
        auto result = false;
        auto letter_on_this_square = board[i][j];

        if (letter_on_this_square == word[idx])
            for (const auto &dir: directions) {
                if (result) break;
                result |= search(idx + 1, word, i + dir.first, j + dir.second, board, visited);
            }

        visited[i][j] = false;

        return result;
    }
};