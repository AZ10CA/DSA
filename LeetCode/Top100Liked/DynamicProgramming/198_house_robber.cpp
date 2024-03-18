#include <vector>

using namespace std;

class Solution {
    vector <vector<int>> memo;
public:

    int traverse(int idx, int can_rob, const vector<int> &nums) {
        if (idx >= nums.size())
            return 0;

        if (!can_rob)
            return traverse(idx + 1, true, nums);

        if (memo[idx][can_rob] != -1)
            return memo[idx][can_rob];

        auto rob = traverse(idx + 1, false, nums) + nums[idx];
        auto skip = traverse(idx + 1, true, nums);

        return memo[idx][can_rob] = std::max(rob, skip);
    }

    int rob(vector<int> &nums) {
        // Time & Space: O(n)
        memo = vector<vector<int>> (nums.size(), vector<int>(2, -1));
        return traverse(0, true, nums);
    }
};