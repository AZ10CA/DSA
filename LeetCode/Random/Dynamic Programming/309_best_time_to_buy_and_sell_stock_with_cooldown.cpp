class Solution {
    vector<vector<int>> table;
public:
    int maxProfit(vector<int>& prices) {
        // Time: O(n), Space: O(n)
        table = vector<vector<int>>(prices.size(), vector<int>(2, -1));
        return dp(0, true,  prices);
    }

    int dp(int idx, bool can_buy, const vector<int>& prices){
        if(idx >= prices.size())
            return 0;

        auto& memo = table[idx][can_buy];
        if(memo != -1)
            return memo;

        auto buy = can_buy ? dp(idx + 1, false, prices) - prices[idx] : INT_MIN;
        auto sell = !can_buy ? dp(idx + 2, true, prices) + prices[idx] : INT_MIN;
        auto skip = dp(idx + 1, can_buy, prices);

        return memo = std::max({buy, sell, skip});
    }
};