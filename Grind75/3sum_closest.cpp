class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Time: O(n^2), Space: O(1)
        int closest_sum;
        int min_diff = INT_MAX;
        std::sort(nums.begin(), nums.end());

        for(int left = 0; left < nums.size() - 2; left++){
            int middle = left + 1;
            int right = nums.size() - 1;
            while(middle < right){
                int sum = nums[left] + nums[middle] + nums[right];
                int diff = std::abs(target - sum);

                if(diff < min_diff){
                    min_diff = diff;
                    closest_sum = sum;
                }

                if(sum == target)
                    return sum;

                if(sum > target)
                    right--;
                else
                    middle++;
            }
        }

        return closest_sum;
    }
};