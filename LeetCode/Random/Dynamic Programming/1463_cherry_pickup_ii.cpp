template<typename T>
T findMax(T val) {
    return val;
}

template<typename T, typename... Args>
T findMax(T first, Args... args) {
    return std::max(first, findMax(args...));
}

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        // states: first robot i, first robot j, second robot i, second robot j
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<vector<vector<int>>>> table(rows, vector<vector<vector<int>>>(cols, vector<vector<int>>(rows, vector<int>(cols, -1))));
        return traverse(0, 0, 0, cols - 1, table, grid);
    }

    bool is_valid(int i, int j, int rows, int cols) {
        return i >= 0 && j >= 0 && i < rows && j < cols;
    }

    int traverse(int fi, int fj, int si, int sj, vector<vector<vector<vector<int>>>>& table, vector<vector<int>>& grid) {
        // Time: O(n^2 * m^2), Space: O(n^2 * m^2)
        const int rows = grid.size(), cols = grid[0].size();

        if (!is_valid(fi, fj, rows, cols) || !is_valid(si, sj, rows, cols))
            return INT_MIN;

        if (fi == rows - 1 && si == rows - 1) {
            if (fj == sj) return grid[fi][fj]; // Both robots on the same cell
            else return grid[fi][fj] + grid[si][sj]; // Different cells
        }

        auto& memo = table[fi][fj][si][sj];
        if (memo != -1)
            return memo;

        int max_cherries = INT_MIN;

        int fb_cherries = grid[fi][fj];
        int sb_cherries = (fj == sj) ? 0 : grid[si][sj]; // Avoid double counting if same cell
        int total_cherries = fb_cherries + sb_cherries;

        for (int d1 = -1; d1 <= 1; ++d1) {
            for (int d2 = -1; d2 <= 1; ++d2) {
                max_cherries = std::max(max_cherries, traverse(fi + 1, fj + d1, si + 1, sj + d2, table, grid));
            }
        }

        return memo = total_cherries + max_cherries;
    }
};