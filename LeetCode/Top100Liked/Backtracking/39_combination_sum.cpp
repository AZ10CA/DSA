class Solution {
public:
    vector<vector<int>> combinationSum(const vector<int> &candidates, int target) {
        vector<vector<int>> result;
        vector<int> nums;

        generate(0, nums, result, candidates, target);

        return result;
    }


    void generate(int idx, int running_sum, vector<int> &selected_nums, vector<vector<int>> &result, const vector<int> &nums,
                  int target) {
        if(running_sum > target)
            return;
        if (running_sum == target) {
            result.push_back(selected_nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            selected_nums.push_back(nums[i]);
            running_sum += nums[i];
            generate(i, running_sum, selected_nums, result, nums, target);
            selected_nums.pop_back();
            running_sum -= nums[i];
        }
    }
};
