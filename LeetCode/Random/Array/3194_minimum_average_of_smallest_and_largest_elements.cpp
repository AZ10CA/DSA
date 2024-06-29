class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        // Time: O(nlogn), Space: O(1)
        std::sort(nums.begin(), nums.end());
        auto min_sum = INT_MAX;
        int left = 0, right = nums.size() - 1;

        while(left < right)
            min_sum = std::min(min_sum, nums[left++] + nums[right--]);

        return (double)min_sum / 2;
    }
};