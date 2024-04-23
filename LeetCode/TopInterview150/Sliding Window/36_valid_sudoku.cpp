class Solution {
public:
    bool isValidSudoku(vector <vector<char>> &board) {
        // Time: O(1), Space: O(1)
        // check rows
        unordered_set<char> seen;
        for (auto row: board) {
            seen.clear();
            for (auto el: row)
                if (el != '.' && seen.find(el) != seen.end())
                    return false;
                else
                    seen.insert(el);
        }
        // check cols
        seen.clear();
        for (int i = 0; i < board.size(); i++) {
            seen.clear();
            for (int j = 0; j < board[i].size(); j++) {
                if (board[j][i] != '.' && seen.find(board[j][i]) != seen.end())
                    return false;
                else
                    seen.insert(board[j][i]);
            }
        }
        seen.clear();
        // check 3x3 squares
        for (int i = 0; i < board.size() / 3; i++) {
            for (int j = 0; j < board.size() / 3; j++) {
                seen.clear();
                for (int z = 0; z < 3; z++) {
                    for (int y = 0; y < 3; y++) {
                        auto new_i = z + i * 3;
                        auto new_j = y + j * 3;
                        if (board[new_i][new_j] != '.' && seen.find(board[new_i][new_j]) != seen.end())
                            return false;
                        else
                            seen.insert(board[new_i][new_j]);
                    }
                }
            }
        }

        return true;
    }
};