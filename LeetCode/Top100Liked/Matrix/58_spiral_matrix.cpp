#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        // Time & Space: O(n^2)
        #define condition result.size() < matrix[0].size() * matrix.size()

        int i_min = 0, i_max = matrix.size() - 1;
        int j_min = 0, j_max = matrix[0].size() - 1;

        vector<int> result;

        while (condition) {
            for (int j = j_min; j <= j_max && condition; j++)
                result.push_back(matrix[i_min][j]);
            i_min++;

            for (int i = i_min; i <= i_max && condition; i++)
                result.push_back(matrix[i][j_max]);
            j_max--;

            for (int j = j_max; j >= j_min && condition; j--)
                result.push_back(matrix[i_max][j]);
            i_max--;

            for (int i = i_max; i >= i_min && condition; i--)
                result.push_back(matrix[i][j_min]);
            j_min++;
        }

        return result;
    }
};