class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        for(int i = 0; i < nums.size() && i <= farthest; i++){
            auto jump = nums[i];
            farthest = std::max(farthest, jump + i);
        }

        if(farthest >= nums.size() - 1)
            return true;

        return false;
    }
};