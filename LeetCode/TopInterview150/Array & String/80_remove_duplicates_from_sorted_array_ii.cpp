class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Time: O(n), Space: O(1)
        auto reader = 1, writer = 1;
        auto prev = nums[0];
        auto prev_count = 1;

        while(reader < nums.size()){
            if(nums[reader] != prev){
                prev = nums[reader];
                nums[writer++] = nums[reader++];
                prev_count = 1;
            } else {
                if(prev_count < 2){
                    nums[writer++] = nums[reader++];
                    prev_count++;
                } else {
                    reader++;
                }
            }
        }

        return writer;
    }
};