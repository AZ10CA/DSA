class Solution {
public:
    vector<int> memo;

    int tribonacci(int n) {
        memo = vector<int>(n + 1, -1);
        return dp(n);
    }

    int dp(int n){
        // Time: O(n), Space: O(n)
        if(n <= 1)
            return n;

        if(n == 2)
            return 1;

        auto& me = memo[n];
        if(me != -1)
            return me;

        return me = dp(n - 1) + dp(n - 2) + dp(n - 3);
    }
};