class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<vector<vector<int>>> table(nums.size(), vector<vector<int>>(2, vector<int>(2, -1)));
        return std::max(traverse(0, true, table, nums, false), traverse(0, false, table, nums, false));
    }

    int traverse(int idx, bool can_rob, vector<vector<vector<int>>>& table, const vector<int>& nums, bool robbed_first){
        if(idx >= nums.size())
            return 0;

        if(idx == nums.size() - 1 && robbed_first)
            can_rob = false;

        auto& memo = table[idx][can_rob][robbed_first];
        if(memo != -1)
            return memo;

        auto rob = can_rob ? nums[idx] + traverse(idx + 1, false, table, nums, idx == 0 ? true : robbed_first) : 0;
        auto skip = traverse(idx + 1, true, table, nums, robbed_first);
        return memo = std::max(skip, rob);
    }
};
