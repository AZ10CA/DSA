class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // Time: O(logn), Space: O(1)
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int m = l + (r - l) / 2;
            auto middle = nums[m];
            auto after = m == nums.size() - 1 ? INT_MIN : nums[m + 1];
            auto before = m == 0 ? INT_MIN : nums[m - 1];

            if(middle < after)
                l = m + 1;
            else if(middle < before)
                r = m - 1;
            else return m;
        }

        return -1;
    }
};
