class Solution {
public:
    void sortColors(vector<int>& nums) {
        dutchNationalFlagSolution(nums);
    }

    void bucketSortSolution(vector<int>& nums){
        // Time: O(n), Space: O(1)
        int ft[3];

        for(auto num: nums)
            ft[num]++;

        int idx = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < ft[i]; j++)
                nums[idx++] = i;
        }
    }

    void dutchNationalFlagSolution(vector<int>& nums){
        // Time: O(n), Space: O(1)
        int left = 0, middle = 0, right = nums.size() - 1;
        while(middle <= right){
            if(nums[middle] == 0){
                std::swap(nums[left], nums[middle]);
                left++;
                middle++;
            } else if(nums[middle] == 1)
                middle++;
            else {
                std::swap(nums[middle], nums[right]);
                right--;
            }
        }
    }
};