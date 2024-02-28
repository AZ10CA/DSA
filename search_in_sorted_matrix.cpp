#include <vector>

using namespace std;


vector<int> horizontalSearch(const vector<vector<int>> &matrix, int target) {
    for (int row = 0; row < matrix.size(); row++) {
        int left = 0, right = matrix[0].size() - 1;
        while (left <= right) {
            auto mid = left + (right - left) / 2;
            int num = matrix[row][mid];
            if (num == target)
                return {row, mid};
            if (target > num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return {-1, -1};
}

vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target) {
    // Time: O(nlogm), Space: O(1)
    return horizontalSearch(matrix, target);
}
