class Solution {
public:
    int jump(vector<int>& nums) {
        return traverse(0, nums);
    }

    int traverse(int idx, const vector<int>& nums){
        // Time: O(n), Space: O(n)
        // NOTE: linear approach is O(1) space but I think this solution is super clean
        if(idx >= nums.size() - 1)
            return 0;

        if(idx + nums[idx] >= nums.size() - 1)
            return 1;

        int max_reach = 0;
        int best_choice = idx + 1;
        for(int i = 1; i <= nums[idx]; i++){
            auto next_step = idx + i + nums[i + idx];
            if(next_step >= max_reach){
                max_reach = next_step;
                best_choice = idx + i;
            }
        }

        return 1 + traverse(best_choice, nums);
    }
};