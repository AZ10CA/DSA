#include <vector>

using namespace std;

vector<vector<int>> transposeMatrix(vector<vector<int>> matrix) {
    // Time & Space: O(n^2)
    vector<vector<int>> transposed(matrix[0].size(), vector<int>(matrix.size(), 0));

    for (int i = 0; i < transposed.size(); i++)
        for (int j = 0; j < transposed[0].size(); j++)
            transposed[i][j] = matrix[j][i];

    return transposed;
}
