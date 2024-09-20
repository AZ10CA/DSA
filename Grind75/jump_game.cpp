class Solution {
public:
    bool canJump(vector<int>& nums) {
        // Time: O(n), Space: O(1)
        int farthest = 0;
        for(int i = 0; i < nums.size() && i <= farthest; i++){
            auto jump = nums[i];
            farthest = std::max(farthest, jump + i);
        }

        return farthest >= nums.size() - 1;
    }
};