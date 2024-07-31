class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> table(amount + 1, vector<int>(coins.size(), -1));
        return dp(0, amount, table, coins);
    }

    int dp(int idx, int amount_left, vector<vector<int>>& table, const vector<int>& coins){
        // Time: O(mn), Space: O(mn)
        if(amount_left == 0)
            return 1;

        if(idx >= coins.size() or amount_left < 0)
            return 0;

        auto& memo = table[amount_left][idx];
        if(memo != -1)
            return memo;

        auto take = dp(idx, amount_left - coins[idx], table, coins);
        auto skip = dp(idx + 1, amount_left, table, coins);

        return memo = take + skip;
    }
};