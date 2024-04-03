class Solution {
    vector<vector<int>> memo;
public:
    int dp(int lastIncluded, int idx, const vector<int> &nums) {
        if (idx == nums.size())
            return 0;

        auto &m = memo[lastIncluded + 1][idx];
        if (m != -1)
            return m;

        // options:
        int include = 0;
        if (lastIncluded == -1 || nums[idx] > nums[lastIncluded])
            include = 1 + dp(idx, idx + 1, nums);
        int skip = dp(lastIncluded, idx + 1, nums);

        return m = std::max(include, skip);
    }

    int lengthOfLIS(vector<int> &nums) {
        // Time & Space: O(n^2)
        // NOTE: tabular approach is more space efficient
        // NOTE: there is a nlogn approach with binary search
        memo = vector<vector<int>> (nums.size() + 1, vector<int>(nums.size(), -1));
        return dp(-1, 0, nums);
    }
};