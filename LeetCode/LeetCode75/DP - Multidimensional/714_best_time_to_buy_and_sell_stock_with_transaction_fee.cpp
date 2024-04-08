class Solution {
public:
    vector<vector<int>> memo;

    int maxProfit(vector<int>& prices, int fee) {
        memo = vector<vector<int>>(prices.size(), vector<int>(2, INT_MIN));
        return dp(0, true, prices, fee);
    }

    int dp(int idx, bool can_buy, const vector<int>& prices, int fee){
        // Time: O(n), Space: O(n)
        if(idx == prices.size())
            return 0;

        auto& me = memo[idx][can_buy];
        if(me != INT_MIN)
            return me;
        // options: buy, sell, skip
        auto buy = 0, sell = 0, skip = 0;
        buy = can_buy ? -fee + dp(idx + 1, false, prices, fee) - prices[idx] : 0;
        sell = !can_buy ? prices[idx] + dp(idx + 1, true, prices, fee) : 0;
        skip = dp(idx + 1, can_buy, prices, fee);

        return me = std::max(std::max(buy, sell), skip);
    }
};