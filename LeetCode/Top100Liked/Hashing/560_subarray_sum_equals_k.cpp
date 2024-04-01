class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Time: O(n), Space: O(n)
        int cnt = 0;
        unordered_map<int, int> prefix_map;
        prefix_map[0] = 1;

        int running_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            running_sum += nums[i];
            int required = running_sum - k;
            if(prefix_map.find(required) != prefix_map.end())
                cnt += prefix_map[required];

            prefix_map[running_sum]++;
        }

        return cnt;
    }
};