#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> memo;
public:
    bool dp(int idx, const vector<int> &nums, int target) {
        if (target == 0)
            return true;

        if (target < 0)
            return false;

        if (idx >= nums.size())
            return false;

        auto &m = memo[idx][target - 1];

        if (m != -1)
            return m;

        return m =
                       dp(idx + 1, nums, target - nums[idx]) ||
                       dp(idx + 1, nums, target);
    }

    bool canPartition(vector<int> &nums) {
        // Time & Space: O(nm) where n: nums.length and m: sum / 2
        int sum = 0;
        for (auto num: nums)
            sum += num;

        if (sum & 1)
            return false;
        sum /= 2;
        memo = vector<vector<int>> (nums.size(), vector<int>(sum, -1));

        return dp(0, nums, sum);
    }
};