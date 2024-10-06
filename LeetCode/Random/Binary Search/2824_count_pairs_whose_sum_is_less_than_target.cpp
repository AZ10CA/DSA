class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        // Time: O(nlogn), Space: O(1)
        std::sort(nums.begin(), nums.end());
        auto cnt = 0;
        int left = 0, right = nums.size() - 1;

        while(left < right){
            auto sum = nums[left] + nums[right];
            if(sum >= target)
                right--;
            else {
                cnt += right - left;
                left++;
            }
        }

        return cnt;
    }
};