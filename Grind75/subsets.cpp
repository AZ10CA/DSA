class Solution {
    vector<vector<int>> result;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // Time: O(2^n), Space: O(2^n)
        vector<int> subset;

        generate(0, subset, nums);

        return result;
    }

    void generate(int idx, vector<int>& subset, const vector<int>& nums){
        if(idx == nums.size()){
            result.push_back(subset);
            return;
        }

        subset.push_back(nums[idx]);
        generate(idx + 1, subset, nums);

        subset.pop_back();
        generate(idx + 1, subset, nums);
    }
};