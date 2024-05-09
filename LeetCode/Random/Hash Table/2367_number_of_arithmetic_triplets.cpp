class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        // Time: O(n), Space: O(n)
        unordered_set<int> nums_set(nums.begin(), nums.end());
        auto cnt = 0;

        for(auto num: nums)
            cnt += nums_set.find(num - diff) != nums_set.end() && nums_set.find(num + diff) != nums_set.end();

        return cnt;
    }
};