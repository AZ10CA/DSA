class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(3, vector<int>(prices.size(), -1)));
        return traverse(0, false, 0, dp, prices);
    }

/* 
states: (3D)
number of transactions done [0,2]
engagement status [0,1]
idx of the item
*/
    int traverse(int idx, bool is_engaged, int tr_count, vector<vector<vector<int>>>& dp, const vector<int>& prices){
        // Time: O(n), Space: O(n)
        if(tr_count == 2 || idx >= prices.size())
            return 0;

        auto& memo = dp[is_engaged][tr_count][idx];
        if(memo != -1)
            return memo;

        auto buy = is_engaged ? INT_MIN : traverse(idx + 1, true, tr_count, dp, prices) - prices[idx];
        auto sell = !is_engaged ? INT_MIN : traverse(idx + 1, false, tr_count + 1, dp, prices) + prices[idx];
        auto skip = traverse(idx + 1, is_engaged, tr_count, dp, prices);

        return memo = std::max(skip, (std::max(buy, sell)));
    }
};