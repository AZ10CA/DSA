class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        /**
        1, 2, 3
        Time & Space: O(2^n)

        2 2 2 --> 2^3 (two choices: 1.include 2.exclude)
        - - -
        */
        vector<int> subset;
        vector<vector<int>> result;

        generate(0, subset, nums, result);

        return result;
    }

    void generate(int idx, vector<int> &subset, const vector<int> &nums, vector<vector<int>> &result) {
        if (idx == nums.size()) {
            result.push_back(subset);
            return;
        }
        auto num = nums[idx];
        subset.push_back(num); // include
        generate(idx + 1, subset, nums, result);
        subset.pop_back(); // exclude
        generate(idx + 1, subset, nums, result);
    }
};