class Solution {
    vector<vector<int>> memo;

public:

    long long getMinSum(int i, int j, const vector<vector<int>> &grid) {
        int rows = grid.size(), cols = grid[0].size();

        if (i >= rows || j >= cols || i < 0 || j < 0)
            return INT_MAX;

        if (i == rows - 1 && j == cols - 1)
            return grid[i][j];

        if (memo[i][j] != -1)
            return memo[i][j];

        return memo[i][j] = std::min(
                getMinSum(i + 1, j, grid),
                getMinSum(i, j + 1, grid)
        ) + grid[i][j];
    }

    int minPathSum(vector<vector<int>> &grid) {
        // Time & Space: O(mn) where m: rows, n: cols
        memo = vector<vector<int>> (grid.size(), vector<int>(grid[0].size(), -1));
        int answer = getMinSum(0, 0, grid);

        return answer;
    }
};