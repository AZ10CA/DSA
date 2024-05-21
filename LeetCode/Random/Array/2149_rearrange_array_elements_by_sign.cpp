class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // Time: O(n), Space: O(n)
        vector<int> pos, neg;
        for(auto each: nums){
            auto& which = each > 0 ? pos : neg;
            which.push_back(each);
        }

        for(int i = 0; i < nums.size() - 1; i+=2){
            nums[i] = pos[i / 2];
            nums[i + 1] = neg[i / 2];
        }

        return nums;
    }
};