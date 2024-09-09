class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Time: O(2^n), Space: O(2^n)
        int sum = 0;
        vector<int> combo;
        vector<vector<int>> result;

        std::sort(candidates.begin(), candidates.end());
        generate(0, sum, combo, result, target, candidates);

        return result;
    }

    void generate(int start_from, int& combo_sum, vector<int>& combo, vector<vector<int>>& result, const int target, const vector<int>& nums){
        if(combo_sum > target)
            return;

        if(combo_sum == target){
            result.push_back(combo);
            return;
        }

        for(int i = start_from; i < nums.size() && combo_sum + nums[i] <= target; i++){
            combo.push_back(nums[i]);
            combo_sum += nums[i];

            generate(i, combo_sum, combo, result, target, nums);

            combo.pop_back();
            combo_sum -= nums[i];
        }
    }
};