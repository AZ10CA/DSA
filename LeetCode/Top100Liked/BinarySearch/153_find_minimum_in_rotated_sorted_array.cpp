#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        // Time: O(logn), Space: O(1)
        auto pivot = find_pivot(nums);
        return nums[pivot + 1];
    }

    int find_pivot(const vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        int result = -1;
        while (left <= right) {
            auto middle = left + (right - left) / 2;
            if (nums[middle] > nums[nums.size() - 1]) {
                left = middle + 1;
                result = middle;
            } else {
                right = middle - 1;
            }
        }

        return result;
    }
};