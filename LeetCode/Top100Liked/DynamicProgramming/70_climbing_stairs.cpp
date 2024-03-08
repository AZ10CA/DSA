#include <vector>

using namespace std;

class Solution {
public:

    int climbStairs(int n) {
        // Time & Space: O(n)
        vector<int> memo(n, -1);
        return dp(0, n, memo);
    }

    int dp(int step, int n, vector<int> &memo) {
        if (step > n)
            return 0;
        if (step == n)
            return 1;

        auto &m = memo[step];
        if (m != -1)
            return m;
        return m = dp(step + 1, n, memo) + dp(step + 2, n, memo);
    }
};