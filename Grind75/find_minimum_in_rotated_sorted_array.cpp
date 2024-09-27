class Solution {
public:
    int findMin(vector<int>& nums) {
        // Time: O(logn(n)), Space: O(1)
        int left = 0, right = nums.size() - 1;
        int idx = INT_MAX;

        while(left <= right){
            auto middle = left + (right - left) / 2;
            auto middle_num = nums[middle];
            if(idx == INT_MAX || middle_num < nums[idx])
                idx = middle;


            if(middle_num <= nums.back() && middle_num >= nums.front()){
                if(idx == INT_MAX || nums.front() < nums[idx])
                    return nums[0];
                else return nums[idx];
            }

            if(middle_num >= nums.front() && middle_num >= nums.back())
                left = middle + 1;
            else
                right = middle - 1;
        }

        return nums[idx];
    }
};