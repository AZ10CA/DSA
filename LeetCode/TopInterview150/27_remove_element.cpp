class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Time: O(n), Space: O(1)
        auto writer = 0, reader = 0;

        while(reader < nums.size()){
            if(nums[reader] != val)
                nums[writer++] = nums[reader++];
            else
                reader++;
        }

        return writer;
    }
};