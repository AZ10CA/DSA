class Solution {
    unordered_map<int, unordered_map<int, int>> table;

public:
    Solution(){
        cin.tie(nullptr);
        cout.tie(nullptr);
        std::ios::sync_with_stdio(false);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // Time: O(ns), Space: O(ns), where s: sum
        return dp(0, nums, 0, target);
    }


    int dp(int idx, const vector<int>& nums, int sum, int target){
        if(idx == nums.size()){
            if(sum == target)
                return 1;
            return 0;
        }


        if(table.find(idx) != table.end()){
            if(table[idx].find(sum) != table[idx].end())
                return table[idx][sum];
        }

        auto plus = dp(idx + 1, nums, sum + nums[idx], target);
        auto minus = dp(idx + 1, nums, sum - nums[idx], target);
        auto result = plus + minus;

        return table[idx][sum] = result;
    }
};