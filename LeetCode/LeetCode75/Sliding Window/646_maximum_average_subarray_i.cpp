class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // Time: O(n), Space: O(1)
        double running_sum = 0;
        for(int i = 0; i < k; i++)
            running_sum += nums[i];

        double max_avg = running_sum / k;

        for(int i = k; i < nums.size(); i++){
            running_sum += nums[i] - nums[i - k];
            max_avg = std::max(max_avg, running_sum / k);
        }

        return max_avg;
    }
};