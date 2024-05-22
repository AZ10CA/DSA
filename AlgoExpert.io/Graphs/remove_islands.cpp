#include <vector>

using namespace std;

#define args i_max, j_max, visited, matrix

void traverse(int i, int j, int i_max, int j_max, vector<vector<int>> &visited, const vector<vector<int>> &matrix) {
    if (i < 0 || j < 0 || i > i_max || j > j_max || matrix[i][j] == 0 || visited[i][j] == true)
        return;

    visited[i][j] = true;

    traverse(i + 1, j, args);
    traverse(i - 1, j, args);
    traverse(i, j - 1, args);
    traverse(i, j + 1, args);
}

vector<vector<int>> removeIslands(vector<vector<int>> matrix) {
    // Time: O(wh), Space: O(wh)
    vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), 0));
    for (int i = 0; i < matrix.size(); i++) {
        traverse(i, 0, matrix.size() - 1, matrix[0].size() - 1, visited, matrix);
        traverse(i, matrix[i].size() - 1, matrix.size() - 1, matrix[0].size() - 1, visited, matrix);
    }

    for (int j = 0; j < matrix[0].size(); j++) {
        traverse(0, j, matrix.size() - 1, matrix[0].size() - 1, visited, matrix);
        traverse(matrix.size() - 1, j, matrix.size() - 1, matrix[0].size() - 1, visited, matrix);
    }
    return visited;
}
