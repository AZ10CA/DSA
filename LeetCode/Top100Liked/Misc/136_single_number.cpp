class Solution {
public:
    int singleNumber(vector<int> &nums) {
        // Time: O(n), Space: O(1)
        auto ans = 0;
        for (auto num: nums)
            ans = ans xor num;

        return ans;
    }
};