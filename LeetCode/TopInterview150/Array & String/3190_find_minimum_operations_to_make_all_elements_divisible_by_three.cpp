class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        // Time: O(n), Space: O(1)
        auto cnt = 0;
        for(auto each: nums)
            cnt += each % 3 != 0;

        return cnt;
    }
};