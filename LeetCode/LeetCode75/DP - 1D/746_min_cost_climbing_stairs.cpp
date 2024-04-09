class Solution {
public:
    vector<int> memo;

    int dp(int idx, const vector<int>& costs){
        if(idx == 0 || idx == 1)
            return 0;

        auto& me = memo[idx];
        if(me != -1)
            return me;
        // options: come from two steps behind or one step behind
        auto one_step = dp(idx - 1, costs) + costs[idx - 1];
        auto two_step = dp(idx - 2, costs) + costs[idx - 2];

        return me = std::min(one_step, two_step);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        // Time: O(n), Space: O(n)
        memo = vector<int>(cost.size() + 1, -1);
        return dp(cost.size(), cost);
    }
};