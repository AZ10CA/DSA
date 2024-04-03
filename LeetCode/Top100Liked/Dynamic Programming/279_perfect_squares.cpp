class Solution {
    vector<int> memo;
public:
    int dp(int amount, const vector<int> &nums) {
        if (amount == 0)
            return 0;

        auto &m = memo[amount - 1];
        if (m != -1)
            return m;

        int answer = INT_MAX;
        for (auto num: nums) {
            int take = (amount - num) < 0 ? INT_MAX : dp(amount - num, nums) + 1;
            answer = std::min(answer, take);
        }

        return m = answer;
    }

    int numSquares(int n) {
        // Time: O(n√n), Space: O(n)
        memo = vector<int>(n, -1);
        vector<int> square_numbers;

        auto num = 1;
        while (num * num <= n) {
            square_numbers.push_back(num * num);
            num++;
        }

        // the question is now similar to coin change problem, square_numbers are our coins and n is the amount
        return dp(n, square_numbers);
    }
};