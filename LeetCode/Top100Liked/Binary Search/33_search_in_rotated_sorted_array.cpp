#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        // Time: O(logn), Space: O(1)
        auto pivot = find_pivot(nums);
        if(pivot == 0)
            return binary_search(nums, 0, nums.size() - 1, target);
        auto before_pivot = binary_search(nums, 0, pivot - 1, target);
        auto after_pivot = binary_search(nums, pivot, nums.size() - 1, target);

        if(before_pivot != -1)
            return before_pivot;
        return after_pivot;
    }

    int binary_search(const vector<int>& nums, int left, int right, int target){
        while(left <= right){
            auto middle = left + (right - left) / 2;
            if(target > nums[middle])
                left = middle + 1;
            else if(target < nums[middle])
                right = middle - 1;
            else return middle;
        }
        return -1;
    }

    int find_pivot(const vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right){
            auto middle = left + (right - left) / 2;
            if(nums[middle] > nums[right]){
                left = middle + 1;
            } else if(nums[middle] < nums[right]){
                right = middle;
            } else {
                return left;
            }
        }
        return left;
    }
};