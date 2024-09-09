class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Time: O(logn), Space: O(1)

        // Phase 1: Find the pivot point
        int pivot = -1;
        int left = 0, right = nums.size() - 1;

        while(left < right){
            int middle = left + (right - left) / 2;
            if(nums[left] <= nums[middle] && nums[middle] <= nums[right])
                break;

            if(nums[middle] > nums[right]){
                pivot = middle;
                left = middle + 1;
            } else
                right = middle;
        }

        // Phase 2: Find the target
        if(pivot == -1)
            return binary_search(0, nums.size() - 1, target, nums);
        else {
            auto greater_section = binary_search(0, pivot, target, nums);
            auto smaller_section = binary_search(pivot + 1, nums.size() - 1, target, nums);

            return std::max(greater_section, smaller_section);
        }
        return 0;
    }

    int binary_search(int left, int right, int target, const vector<int>& nums){
        while(left <= right){
            int middle = left + (right - left) / 2;
            if(nums[middle] == target)
                return middle;

            if(nums[middle] < target)
                left = middle + 1;
            else
                right = middle - 1;
        }

        return -1;
    }
};