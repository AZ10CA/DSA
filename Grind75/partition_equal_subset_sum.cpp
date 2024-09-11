class Solution {
    vector<vector<int>> table;
public:
    bool canPartition(vector<int>& nums) {
        // Time: O(nm), Space: O(nm), where m: half the total sum of nums
        int sum = 0;
        for(auto num: nums)
            sum += num;

        if(sum & 1)
            return false;

        int target = sum >> 1;
        table = vector<vector<int>>(nums.size(), vector<int>(target + 1, -1));

        return canMake(0, nums, target);
    }

    bool canMake(int idx, const vector<int>& nums, int target){
        if(target == 0)
            return true;

        if(idx == nums.size() || target < 0)
            return false;

        auto& memo = table[idx][target];

        if(memo != -1)
            return memo;

        auto take = canMake(idx + 1, nums, target - nums[idx]);
        auto skip = canMake(idx + 1, nums, target);

        return memo = take || skip;
    }
};