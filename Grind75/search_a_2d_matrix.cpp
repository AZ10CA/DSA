class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Time: O(log(mn)), Space: O(1)
        int rows = matrix.size();
        int cols = matrix[0].size();
        int size = rows * cols;

        int left = 0, right = size - 1;
        while(left <= right){
            auto middle = left + (right - left) / 2;
            const auto&[i, j] = to_matrix_idx(middle, rows, cols);
            auto& element = matrix[i][j];

            if(element == target)
                return true;

            if(element > target)
                right = middle - 1;
            else
                left = middle + 1;
        }

        return false;
    }

    pair<int, int> to_matrix_idx(int idx, int rows, int cols){
        int row = idx / cols;
        idx -= row * cols;
        int col = idx;

        return {row, col};
    }
};