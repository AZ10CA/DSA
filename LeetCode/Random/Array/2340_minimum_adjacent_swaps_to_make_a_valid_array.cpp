class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        // Time: O(n), Space: O(1)
        int min_element = INT_MAX;
        int min_idx;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < min_element){
                min_element = nums[i];
                min_idx = i;
            }
        }

        int max_element = INT_MIN;
        int max_idx;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] > max_element){
                max_element = nums[i];
                max_idx = i;
            }
        }

        int sz = (int)nums.size();
        if(min_idx == max_idx)
            return 0;

        return sz - max_idx - 1 + min_idx - (max_idx < min_idx);
    }
};