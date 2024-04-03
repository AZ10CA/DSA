class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        // Time: O(logn), Space: O(1)
        auto right = find(nums, target, false);
        auto left = find(nums, target, true);

        return {left, right};
    }

    int find(const vector<int> &nums, int target, bool leftmost) {
        int left = 0, right = nums.size() - 1;
        int result = -1;
        while (left <= right) {
            auto middle = left + (right - left) / 2;
            if (target == nums[middle]) {
                if (leftmost)
                    right = middle - 1;
                else
                    left = middle + 1;
                result = middle;
            } else if (target > nums[middle]) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return result;
    }
};