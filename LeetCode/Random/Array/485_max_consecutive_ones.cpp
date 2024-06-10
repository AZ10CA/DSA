class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // Time: O(n), Space: O(1)
        int max_ones = 0;
        int current_streak = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1)
                current_streak++;
            else {
                max_ones = std::max(current_streak, max_ones);
                current_streak = 0;
            }
        }

        max_ones = std::max(max_ones, current_streak);

        return max_ones;
    }
};