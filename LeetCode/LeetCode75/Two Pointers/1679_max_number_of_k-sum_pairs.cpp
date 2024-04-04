class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // Time: O(nlogn), Space: O(1)
        std::sort(nums.begin(), nums.end());
        int fp = 0, sp = nums.size() - 1;
        int solutions = 0;

        while(fp < sp){
            auto sum = nums[fp] + nums[sp];
            if(sum == k){
                solutions++;
                fp++;
                sp--;
            } else if(sum < k)
                fp++;
            else
                sp--;
        }

        return solutions;
    }
};