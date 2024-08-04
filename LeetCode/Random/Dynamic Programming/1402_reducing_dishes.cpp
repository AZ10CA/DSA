class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        // Time: O(n^2), Space: O(n^2)
        vector<vector<int>> table(satisfaction.size(), vector<int>(satisfaction.size() + 1, - 1));
        std::sort(satisfaction.begin(), satisfaction.end());
        return dp(0, 1, table, satisfaction);
    }


    int dp(int idx, int time, vector<vector<int>>& table, const vector<int>& dishes){
        if(idx == dishes.size())
            return 0;

        auto& memo = table[idx][time];
        if(memo != -1)
            return memo;

        auto take = dp(idx + 1, time + 1, table, dishes) + dishes[idx] * time;
        auto skip = dp(idx + 1, time, table, dishes);

        return memo = std::max(take, skip);
    }
};