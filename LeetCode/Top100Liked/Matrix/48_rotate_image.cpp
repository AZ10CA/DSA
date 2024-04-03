class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        // Time: O(n^2), Space: O(1)
        for (int i = 0; i < matrix.size(); i++)
            for (int j = i; j < matrix.size(); j++)
                std::swap(matrix[i][j], matrix[j][i]);

        for (int i = 0; i < matrix.size(); i++)
            std::reverse(matrix[i].begin(), matrix[i].end());
    }
};