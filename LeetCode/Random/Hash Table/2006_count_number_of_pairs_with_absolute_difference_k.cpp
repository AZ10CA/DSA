class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        // Time: O(n), Space: O(m), m: number of unique elements in nums

        unordered_map<int, int> nums_map;
        auto cnt = 0;

        for(auto num: nums)
            nums_map[num]++;

        for(auto&[num, frequency]: nums_map)
            if(nums_map.find(num + k) != nums_map.end())
                cnt += frequency * nums_map[num + k];

        return cnt;
    }
};