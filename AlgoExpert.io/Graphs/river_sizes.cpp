#include <vector>

using namespace std;

int traverse(int i, int j, vector<vector<bool>> &visited, const vector<vector<int>> &matrix) {
    if (i < 0 || j < 0 || i >= visited.size() || j >= visited[0].size() || visited[i][j] || matrix[i][j] == 0)
        return 0;

    visited[i][j] = true;

    return 1 +
           traverse(i + 1, j, visited, matrix) +
           traverse(i - 1, j, visited, matrix) +
           traverse(i, j + 1, visited, matrix) +
           traverse(i, j - 1, visited, matrix);
}


vector<int> riverSizes(vector<vector<int>> matrix) {
    // Time & Space: O(wh)
    vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
    vector<int> islands;

    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 0 || visited[i][j])
                continue;
            else
                islands.push_back(traverse(i, j, visited, matrix));
        }
    return islands;
}


