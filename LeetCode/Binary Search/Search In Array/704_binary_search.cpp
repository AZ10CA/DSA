class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Time: O(logn), Space: O(1)
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            auto middle = left + (right - left) / 2;

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