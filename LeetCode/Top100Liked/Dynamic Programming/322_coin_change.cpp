class Solution {
    vector<int> memo;

public:
    unsigned int dp(int amount, const vector<int>& coins){
        if(amount == 0)
            return 0;

        auto& m = memo[amount];
        if(m != -1)
            return m;

        unsigned int answer = INT_MAX;
        for(auto coin: coins){
            auto take = (amount - coin) >= 0 ? dp(amount - coin, coins) + 1 : INT_MAX;
            answer = std::min(answer, take);
        }

        return m = answer;
    }

    int coinChange(vector<int>& coins, int amount) {
        // Time: O(mn) where m: coins.size() and n: amount, Space: O(n)
        memo = vector<int>(amount + 1, -1);
        auto answer = dp(amount, coins);
        if(answer == INT_MAX)
            return -1;

        return answer;
    }
};