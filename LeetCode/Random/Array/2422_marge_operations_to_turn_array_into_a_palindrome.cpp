class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        // Time: O(n), Space: O(1)
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int l_idx = 0, r_idx = nums.size() - 1, operations = 0;

        while(l_idx < r_idx){
            if(nums[l_idx] == nums[r_idx]){
                l_idx++;
                r_idx--;
                continue;
            }

            auto& smaller = nums[l_idx] < nums[r_idx] ? nums[l_idx] : nums[r_idx];
            auto& larger = smaller == nums[l_idx] ? nums[r_idx] : nums[l_idx];

            larger -= smaller;
            smaller = 0;


            if(nums[l_idx] < nums[r_idx]){
                l_idx++;
                operations++;
            } else {
                r_idx--;
                operations++;
            }
        }

        return operations;
    }

};