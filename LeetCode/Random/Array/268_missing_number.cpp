class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Time: O(n), Space: O(1)
        for(auto& num: nums)
            num++;

        nums.push_back(42);

        for(int i = 0; i < nums.size() - 1; i++){
            auto num = std::abs(nums[i]);
            auto index = num - 1;
            nums[index] *= -1;
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0)
                return i;
        }

        return -1;
    }
};