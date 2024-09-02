class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Time: O(n), Space: O(1)
        int cnt = 0;
        int last_num;
        for(int i = 0; i < nums.size(); i++){
            if(cnt == 0){
                cnt = 1;
                last_num = nums[i];
                continue;
            }

            if(nums[i] == last_num)
                cnt++;
            else
                cnt--;
        }

        return last_num;
    }
};