class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Time: O(n), Space: O(1)
        auto reader = 0, writer = 0;
        while(reader < nums.size()){
            if(nums[reader] == 0){
                reader++;
                continue;
            }

            nums[writer++] = nums[reader++];
        }

        while(writer < nums.size())
            nums[writer++] = 0;
    }
};