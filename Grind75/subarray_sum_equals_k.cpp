class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Time: O(n), Space: O(n)
        int result = 0;
        int running_sum = 0;

        unordered_map<int, int> prefix_sums;
        prefix_sums[0] = 1; // there is one way to have the subarray sum of 0 -> [] (empty array)


        for(int i = 0; i < nums.size(); i++){
            running_sum += nums[i];
            int required = running_sum - k;

            if(prefix_sums.find(required) != prefix_sums.end())
                result += prefix_sums[required];

            prefix_sums[running_sum]++;
        }

        return result;
    }
};