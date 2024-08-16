class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        // Time: O(n), Space: O(n)
        vector<int> left_sum(nums.size(), 0), right_sum(nums.size(), 0);
        for(int i = 1; i < nums.size(); i++)
            left_sum[i] = left_sum[i - 1] + nums[i - 1];

        for(int i = nums.size() - 2; i >= 0; i--)
            right_sum[i] = nums[i + 1] + right_sum[i + 1];


        vector<int> result(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++)
            result[i] = std::abs(left_sum[i] - right_sum[i]);

        return result;
    }
};