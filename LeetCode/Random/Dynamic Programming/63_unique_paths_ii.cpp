class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        // Time: O(nm), Space: O(nm)
        vector<vector<int>> table(g.size(), vector<int>(g[0].size(), -1));
        return traverse(0, 0, table, g);
    }

    int traverse(int i, int j, vector<vector<int>>& table, const vector<vector<int>>& grid){
        auto rows = grid.size();
        auto cols = grid[0].size();

        if(i >= rows || j >= cols || grid[i][j])
            return 0;

        if(i == rows - 1 && j == cols - 1)
            return 1;

        auto& memo = table[i][j];
        if(memo != -1)
            return memo;

        return memo = traverse(i + 1, j, table, grid) + traverse(i, j + 1, table, grid);
    }
};