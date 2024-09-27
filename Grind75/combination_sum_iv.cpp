class Solution {
    vector<int> table;
public:
    int combinationSum4(vector<int>& nums, int target) {
        // Time: O(n^2), Space: O(m), where m: target
        int sum = 0, count = 0;
        table = vector<int>(target + 1, -1);

        return generate(nums, target);
    }

    int generate(const vector<int>& nums, int target){
        if(target == 0)
            return 1;

        if(target < 0)
            return 0;

        auto& memo = table[target];
        if(memo != -1)
            return memo;

        int count = 0;
        for(auto num: nums)
            count += generate(nums, target - num);

        return memo = count;
    }
};