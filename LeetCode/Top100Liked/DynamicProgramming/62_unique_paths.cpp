#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> memo;

    int dp(int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i == m || j == n)
            return 0;

        if (i == m - 1 && j == n - 1)
            return 1;

        if (memo[i][j] != -1)
            return memo[i][j];

        return memo[i][j] = dp(i + 1, j, m, n) + dp(i, j + 1, m, n);
    }

    int uniquePaths(int m, int n) {
        // Time & Space: O(mn)
        memo = vectorvector<int>> (m, vector<int>(n, -1));
        return dp(0, 0, m, n);
    }
};

/**
    This question could be solve in O(min(m, n)) time and O(1) space with the mathematical approach
    (m + n - 2)! / ((m - 1)!(n - 1)!)
*/