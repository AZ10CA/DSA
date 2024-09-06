class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Time: O(n^2), Space: O(n^2)
        vector<vector<int>> result;
        std::sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++){
            auto selected = nums[i];
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = nums.size() - 1;

            while(left < right){
                auto sum = nums[left] + nums[right];
                if(sum + selected == 0){
                    vector<int> triplet = {selected, nums[left], nums[right]};
                    result.push_back(triplet);

                    while(left < right && nums[left] == nums[left + 1])
                        left++;

                    while(left < right && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                } else if(sum + selected < 0)
                    left++;
                else right--;
            }
        }

        return result;
    }
};