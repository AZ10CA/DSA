class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        // Time: O(logn), Space: O(1)
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            auto middle = left + (right - left) / 2;
            auto num = nums[middle];

            if (target == num)
                return middle;

            if (target > num)
                left = middle + 1;
            else
                right = middle - 1;
        }

        return left;
    }
};