class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Time: O(n), Space: O(1)
        auto reader = 0, writer = 0;
        auto prev = INT_MIN;

        while(reader < nums.size()){
            if(nums[reader] != prev){
                prev = nums[reader];
                nums[writer++] = nums[reader++];
            } else
                reader++;
        }

        return writer;
    }
};