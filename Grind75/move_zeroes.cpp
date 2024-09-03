class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Time: O(n), Space: O(1)
        int reader = 0, writer = 0;

        while(reader < nums.size() && writer < nums.size()){
            if(nums[writer] != 0){
                writer++;
                continue;
            }

            if(nums[reader] == 0 || reader <= writer){
                reader++;
                continue;
            }

            // now writer points to 0 and reader points to a non-zero number
            nums[writer] = nums[reader];
            nums[reader] = 0;

            writer++;
            reader++;
        }
    }
};