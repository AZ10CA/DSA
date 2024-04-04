class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // Time: O(n), Space: O(n)
        vector<int> prefix(nums.size()), postfix(nums.size());
        int running_sum = 0;

        for(int i = 0; i < nums.size(); i++){
            prefix[i] = running_sum;
            running_sum += nums[i];
        }

        running_sum = 0;
        for(int i = nums.size() - 1; i >= 0; i--){
            postfix[i] = running_sum;
            running_sum += nums[i];
        }

        for(int i = 0; i < nums.size(); i++){
            if(prefix[i] == postfix[i])
                return i;
        }

        return -1;
    }
};