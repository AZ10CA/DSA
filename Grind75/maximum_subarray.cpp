class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // return divide_and_conquer(0, nums.size() - 1, nums);
        return kadane_algo(nums);
    }

    int kadane_algo(const vector<int>& nums){
        // Time: O(n), Space: O(1)
        int mx = INT_MIN;
        int sum = 0;
        for(auto num: nums){
            sum += num;
            mx = std::max(mx, sum);
            sum = std::max(0, sum);
        }

        return mx == INT_MIN ? -1 : mx;
    }


    int divide_and_conquer(int left, int right, const vector<int>& nums){
        // Time: O(nlogn), Space: O(logn)
        if(left == right)
            return nums[left];

        auto middle = left + (right - left) / 2;

        auto l = divide_and_conquer(left, middle, nums);
        auto r = divide_and_conquer(middle + 1, right, nums);

        // cross sum calculation
        auto lss = INT_MIN, rss = INT_MIN, sum = 0;

        for(int i = middle; i >= left; i--){
            sum += nums[i];
            lss = std::max(sum, lss);
        }

        sum = 0;
        for(int i = middle + 1; i <= right; i++){
            sum += nums[i];
            rss = std::max(sum, rss);
        }

        auto cross_ss = lss + rss;

        return std::max({cross_ss, l, r});
    }
};