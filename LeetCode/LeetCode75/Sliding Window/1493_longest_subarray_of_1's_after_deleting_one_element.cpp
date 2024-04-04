class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int deleted_index = -1;
        int start = 0, end = 0;
        int max_size = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                end = i;
            } else if(nums[i] == 0){
                if(deleted_index == -1){
                    end = i;
                    deleted_index = i;
                } else {
                    start = deleted_index + 1;
                    end = i;
                    deleted_index = i;
                }
            }
            max_size = std::max(max_size, end - start);
        }

        return max_size;
    }
};