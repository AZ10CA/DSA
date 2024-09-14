class Solution {
    vector<int> table;
public:
    int rob(vector<int>& nums) {
        // Time: O(n), Space: O(n)
        table = vector<int>(nums.size(), -1);

        return dp(0, nums);
    }

    int dp(int idx, const vector<int>& nums){
        if(idx >= nums.size())
            return 0;

        auto& memo = table[idx];
        if(memo != -1)
            return memo;

        auto rob = nums[idx] + dp(idx + 2, nums);
        auto skip = dp(idx + 1, nums);

        return memo = std::max(rob, skip);
    }
};