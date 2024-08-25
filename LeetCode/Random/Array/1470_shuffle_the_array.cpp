class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // Time: O(n), Space: O(n)
        vector<int> result(n * 2);
        int idx = 0;

        for(int i = 0; i < n * 2; i += 2, idx++){
            result[i] = nums[idx];
            result[i + 1] = nums[idx + n];
        }
        return result;
    }
};