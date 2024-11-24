class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Time: O(2^n), Space: O(n)
        vector<int> combo;
        vector<vector<int>> result;
        std::sort(candidates.begin(), candidates.end());

        backtrack(0, target, combo, result, candidates);

        return result;
    }

    void backtrack(int idx, int target, vector<int>& combo, vector<vector<int>>& result, const vector<int>& nums){
        if(target < 0)
            return;

        if(target == 0){
            result.push_back(combo);
            return;
        }

        for(int i = idx; i < nums.size(); i++){
            if(i > idx && nums[i] == nums[i - 1])
                continue;
            combo.push_back(nums[i]);
            backtrack(i + 1, target - nums[i], combo, result, nums);
            combo.pop_back();
        }
    }
};