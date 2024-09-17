class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Time: O(n), Space: O(1)
        for(int i = 0; i < nums.size(); i++){
            int idx = std::abs(nums[i]) - 1;
            if(nums[idx] < 0)
                return idx + 1;

            nums[idx] *= -1;
        }

        return 42;
    }
};