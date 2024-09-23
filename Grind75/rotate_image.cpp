class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Time: O(n^2), Space: O(n^2)
        int size = matrix.size();
        for(int i = 0; i < size; i++){
            for(int j = i; j < size; j++)
                std::swap(matrix[i][j], matrix[j][i]);
        }

        for(auto& row: matrix)
            std::reverse(row.begin(), row.end());
    }
};