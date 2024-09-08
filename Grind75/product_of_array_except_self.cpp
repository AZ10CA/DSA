class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Time: O(n), Space: O(n)
        vector<int> pre(nums.size(), 1), post(nums.size(), 1);

        for(int i = 0; i < nums.size(); i++){
            auto left = i == 0 ? 1 : pre[i - 1];
            pre[i] = left * nums[i];
        }

        for(int i = nums.size() - 1; i >= 0; i--){
            auto right = i == nums.size() - 1 ? 1 : post[i + 1];
            post[i] = right * nums[i];
        }

        vector<int> result(nums.size(), 1);

        for(int i = 0; i < nums.size(); i++){
            auto left = i == 0 ? 1 : pre[i - 1];
            auto right = i == nums.size() - 1 ? 1 : post[i + 1];
            result[i] = left * right;
        }


        return result;
    }
};