class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binary_search_1(0, nums.size() - 1, nums, target);
    }

    int binary_search_1(int left, int right, const vector<int>& nums, int target){
        // Time: O(logn), Space: O(logn) *recursion overhead
        if(left > right)
            return -1;

        auto middle = left + (right - left) / 2;
        if(nums[middle] == target)
            return middle;

        if(nums[middle] > target)
            return binary_search_1(left, middle - 1, nums, target);

        return binary_search_1(middle + 1, right, nums, target);
    }

    int binary_search_2(const vector<int>& nums, int target){
        // Time: O(logn), Space: O(1)
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            auto middle = left + (right - left) / 2;
            if(nums[middle] == target)
                return middle;
            if(nums[middle] > target)
                right = middle - 1;
            else
                left = middle + 1;
        }

        return -1;
    }
};