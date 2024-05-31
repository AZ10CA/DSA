class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Time: O(n), Space: O(n)
        unordered_set<int> nums_set(nums.begin(), nums.end());
        return nums_set.size() != nums.size();
    }
};