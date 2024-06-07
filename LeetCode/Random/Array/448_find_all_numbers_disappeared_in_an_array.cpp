class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // Time: O(n), Space: O(n)
        for(auto num: nums){
            auto idx = std::abs(num) - 1;
            nums[idx] = -std::abs(nums[idx]);
        }

        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0)
                result.push_back(i + 1);
        }

        return result;
    }
};