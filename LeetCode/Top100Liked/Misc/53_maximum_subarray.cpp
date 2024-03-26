class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        // Time: O(n), Space: O(1)
        int sum = nums[0];
        int answer = sum;

        for (int i = 1; i < nums.size(); i++) {
            sum = std::max(sum + nums[i], nums[i]);
            answer = std::max(sum, answer);
        }

        return answer;
    }
};