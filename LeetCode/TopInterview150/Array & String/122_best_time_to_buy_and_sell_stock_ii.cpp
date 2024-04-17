class Solution {
    vector<vector<int>> memo;
public:
    int maxProfit(vector<int>& prices) {
        // Time: O(n), Space: O(n)
        memo = vector<vector<int>>(prices.size(), vector<int>(2, -1));
        return dp(0, prices, true);
    }

    int dp(int idx, const vector<int>& prices, bool can_buy){
        if(idx == prices.size())
            return 0;

        auto& me = memo[idx][can_buy];

        if(me != -1)
            return me;

        auto buy = can_buy ? dp(idx + 1, prices, false) - prices[idx] : 0;
        auto sell = not can_buy ? dp(idx + 1, prices, true) + prices[idx] : 0;
        auto skip = dp(idx + 1, prices, can_buy);

        return me = std::max(std::max(buy, sell), skip);
    }
};
