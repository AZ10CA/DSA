class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Time: O(n), Space: O(1)
        int missing = 0;

        for(auto num: nums)
            missing = missing xor num;

        return missing;
    }
};