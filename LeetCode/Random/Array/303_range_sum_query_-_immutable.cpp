class NumArray {
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        // Time: O(n), Space: O(n)
        prefix = vector<int>(nums.size(), 0);

        for(int i = 0; i < nums.size(); i++){
            auto left = i > 0 ? prefix[i - 1] : 0;
            prefix[i] = left + nums[i];
        }
    }

    int sumRange(int left, int right) {
        // Time: O(1), Space: O(1)
        auto left_sum = left > 0 ? prefix[left - 1] : 0;
        return prefix[right] - left_sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */