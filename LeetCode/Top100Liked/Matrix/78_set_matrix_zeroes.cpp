class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        // Time: O(mn), Space: O(m + n)
        unordered_set<int> rows;
        unordered_set<int> cols;

        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }

        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
                if (rows.find(i) != rows.end() || cols.find(j) != cols.end())
                    matrix[i][j] = 0;
    }
};