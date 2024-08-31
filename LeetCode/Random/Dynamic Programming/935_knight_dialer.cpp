class Solution {
    int table[4][3][5000];
    const int MOD = 1000000007;
    vector<vector<int>> moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
public:
    int knightDialer(int n) {
        // Time: O(n), Space: O(n)
        memset(table, -1, sizeof(table));
        int count = 0;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (!(i == 3 && j == 0) && !(i == 3 && j == 2)) {
                    count = (count + traverse(i, j, n - 1)) % MOD;
                }
            }
        }
        return count;
    }

    int traverse(int i, int j, int n) {
        if (i < 0 || j < 0 || i >= 4 || j >= 3 || (i == 3 && j == 0) || (i == 3 && j == 2))
            return 0;

        if (n == 0)
            return 1;

        int &memo = table[i][j][n];
        if (memo != -1)
            return memo;

        memo = 0;

        for (auto &dir : moves) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            memo = (memo + traverse(new_i, new_j, n - 1)) % MOD;
        }

        return memo;
    }
};