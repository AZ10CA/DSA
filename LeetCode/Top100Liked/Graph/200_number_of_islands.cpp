#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int islands = 0;

        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++) {
                if (visited[i][j] || grid[i][j] == '0')
                    continue;
                traverse(i, j, grid, visited);
                islands++;
            }

        return islands;
    }

    void traverse(int i, int j, const vector<vector<char>> &grid, vector<vector<bool>> &visited) {
        if (visited[i][j] || grid[i][j] == '0')
            return;

        visited[i][j] = true;
        vector<pair<int, int>> directions = {{0,  1},
                                             {1,  0},
                                             {0,  -1},
                                             {-1, 0}};

        for (auto dir: directions) {
            auto new_i = i + dir.first;
            auto new_j = j + dir.second;
            if (new_i >= 0 && new_j >= 0 && new_i < grid.size() && new_j < grid[0].size())
                traverse(new_i, new_j, grid, visited);
        }
    }
};