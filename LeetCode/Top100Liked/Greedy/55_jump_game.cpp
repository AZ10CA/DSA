class Solution {
public:
    bool canJump(vector<int>& nums) {
        return traverse(0, nums);
    }

    bool traverse(int idx, const vector<int>& nums){
        // Time: O(n), Space: O(n)
        // NOTE: Iterative solution of this approach is O(1) space
        if(idx == nums.size() - 1 || idx + nums[idx] >= nums.size() - 1)
            return true;

        auto farthest = 0;
        auto next_idx = idx;
        for(int i = 1; i <= nums[idx]; i++){
            if(idx + i + nums[i + idx] >= farthest){
                farthest = nums[i + idx] + i + idx;
                next_idx = idx + i;
            }
        }

        return next_idx == idx ? false : traverse(next_idx, nums);
    }
};