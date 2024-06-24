class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        // Time: O(n), Space: O(n)
        vector<int> result(nums.size());
        int idx = 0;

        for(auto num: nums){
            result[idx] = nums[num];
            idx++;
        }

        return result;
    }
};