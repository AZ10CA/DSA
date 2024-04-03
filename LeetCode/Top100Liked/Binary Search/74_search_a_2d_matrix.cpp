#include <vector>

using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        // Time: O(log(n * m)), Space: O(1)
        int row_count = matrix.size();
        int col_count = matrix[0].size();

        int left = 0, right = row_count * col_count - 1;
        while (left <= right) {
            auto middle = left + (right - left) / 2;
            auto coord = idx_to_matrix_position(middle, row_count, col_count);
            auto middle_num = matrix[coord.first][coord.second];

            if (middle_num == target)
                return true;
            if (target > middle_num)
                left = middle + 1;
            else
                right = middle - 1;
        }

        return false;
    }

    pair<int, int> idx_to_matrix_position(int idx, int row_count, int col_count) {
        int row = idx / col_count;
        int col = idx - (row * col_count);

        return {row, col};
    }
};