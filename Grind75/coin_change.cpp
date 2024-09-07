class Solution {
    vector<int> table;
public:
    int coinChange(vector<int>& coins, int amount) {
        // Time: O(nm), Space: O(m), m: amount
        table = vector<int>(amount + 1, -1);
        auto result = dp(amount, coins);
        return result == INT_MAX ? -1 : result;
    }

    int dp(int amount, const vector<int>& coins){
        if(amount < 0)
            return INT_MAX;

        if(amount == 0)
            return 0;

        auto& memo = table[amount];
        if(memo != -1)
            return memo;

        int answer = INT_MAX;
        for(auto coin: coins){
            auto count = dp(amount - coin, coins);
            if(count == INT_MAX)
                continue;
            answer = std::min(answer, count + 1);
        }

        return memo = answer;
    }
};