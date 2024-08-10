class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> table(prices.size(), vector<vector<int>>(k + 1, vector<int>(2, -1)));
        return dp(0, k, true, table, prices);
    }

    int dp(int current_day, int remaining_transactions, bool can_buy, vector<vector<vector<int>>>& table, const vector<int>& prices){
        if(current_day == prices.size() || remaining_transactions == 0)
            return 0;

        auto& memo = table[current_day][remaining_transactions][can_buy];
        if(memo != -1)
            return memo;
        auto buy = INT_MIN, sell = INT_MIN;
        if(can_buy)
            buy = dp(current_day + 1, remaining_transactions, false, table, prices) - prices[current_day];

        if(!can_buy)
            sell = dp(current_day + 1, remaining_transactions - 1, true, table, prices) + prices[current_day];

        auto skip = dp(current_day + 1, remaining_transactions, can_buy, table, prices);

        return memo = std::max(std::max(buy, sell), skip);
    }
};