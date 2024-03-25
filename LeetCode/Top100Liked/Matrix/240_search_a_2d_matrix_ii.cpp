#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        // Time: O(n + m), Space: O(1)
        int i = 0, j = matrix[0].size() - 1;

        while (i >= 0 && j >= 0 && j < matrix[0].size() && i < matrix.size()) {
            auto current = matrix[i][j];
            if (target == current)
                return true;
            if (target < current)
                j--;
            else i++;
        }

        return false;
    }
};