class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // Time: O(n), Space: O(1)
        int max_pos_sum = INT_MIN;
        int min_neg_sum = INT_MAX;
        int current_pos_sum = 0;
        int current_neg_sum = 0;
        for(auto& num: nums){
            current_pos_sum += num;
            current_neg_sum += num;
            max_pos_sum = std::max(max_pos_sum, current_pos_sum);
            min_neg_sum = std::min(min_neg_sum, current_neg_sum);

            current_pos_sum = std::max(0, current_pos_sum);
            current_neg_sum = std::min(0, current_neg_sum);
        }

        return std::max(max_pos_sum, -min_neg_sum);
    }
};