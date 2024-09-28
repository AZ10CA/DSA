class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // Time: O(n), Space: O(1)
        // find the pivot point
        int pivot_idx = -1;
        for(int i = nums.size() - 1; i > 0; i--)
            if(nums[i - 1] < nums[i]){
                pivot_idx = i - 1;
                break;
            }

        if(pivot_idx == -1){ // sorted in descending order
            std::reverse(nums.begin(), nums.end());
            return;
        }

        // find the first element in the right side that is greater than the pivot number
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] > nums[pivot_idx]){
                std::swap(nums[i], nums[pivot_idx]);
                break;
            }
        }

        // reverse all numbers after the pivot point
        std::reverse(nums.begin() + pivot_idx + 1, nums.end());
    }
};