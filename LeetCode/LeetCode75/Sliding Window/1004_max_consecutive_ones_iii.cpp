class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int flips = 0;
        int start = 0, end = 0;
        int max_size = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1)
                end = i;
            else if(nums[i] == 0) {
                if(flips < k){
                    flips++;
                    end = i;
                } else {
                    if(start == end){
                        start = i + 1;
                        end = i + 1;
                        continue;
                    }

                    flips -= nums[start] == 0;
                    start++;
                    i--;

                }
            }
            max_size = std::max(max_size, end - start + 1);
        }

        return max_size;
    }
};