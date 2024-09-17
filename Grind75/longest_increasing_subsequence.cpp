class Solution {
    vector<vector<int>> table;
public:
    int lengthOfLIS(vector<int>& nums) {
        // Time: O(n^2), Space: O(n^2)
        table = vector<vector<int>>(nums.size(), vector<int>(nums.size() + 1, -1));

        return dp(-1, 0, nums);
    }

    int dp(int last_idx, int idx, const vector<int>& nums){
        if(idx == nums.size())
            return 0;

        auto& memo = table[idx][last_idx + 1];
        if(memo != -1)
            return memo;

        auto skip = dp(last_idx, idx + 1, nums);
        auto include = last_idx == -1 || nums[last_idx] < nums[idx] ? dp(idx, idx + 1, nums) + 1 : 0;

        return memo = std::max(skip, include);
    }
};