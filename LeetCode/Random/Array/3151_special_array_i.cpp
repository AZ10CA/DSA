class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        // Time: O(n), Space: O(1)
        bool parity = true;
        for(int i = 0; i < nums.size() - 1; i++)
            parity &= nums[i] % 2 != nums[i + 1] % 2;

        return parity;
    }
};