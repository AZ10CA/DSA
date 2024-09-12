class Solution {
public:
    int uniquePaths(int m, int n) {
        // Time: O(nm), Space: O(nm)
        vector<vector<int>> table(m, vector<int>(n, -1));

        return dp(0, 0, table);
    }

    int dp(int i, int j, vector<vector<int>>& table){
        int rows = table.size(), cols = table[0].size();
        if(i < 0 || j < 0 || i >= rows || j >= cols)
            return 0;

        if(i == rows - 1 && j == cols - 1)
            return 1;

        auto& memo = table[i][j];
        if(memo != -1)
            return memo;

        auto right = dp(i, j + 1, table);
        auto down = dp(i + 1, j, table);

        return memo = right + down;
    }
};