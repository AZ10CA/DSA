#include <vector>

using namespace std;

int dp(int amount, const vector<int> &coins, vector<int> &memo);

int minNumberOfCoinsForChange(int n, vector<int> denoms) {
    // Time: O(nd), Space: O(n)
    vector<int> memo(n + 1, -1);
    auto ans = dp(n, denoms, memo);
    return ans == INT_MAX - 1 ? -1 : ans;
}

int dp(int amount, const vector<int> &coins, vector<int> &memo) {
    if (amount == 0)
        return 0;
    if (memo[amount] != -1)
        return memo[amount];
    int min_coins = INT_MAX - 1;
    for (auto coin: coins)
        if (amount - coin >= 0)
            min_coins = std::min(min_coins, dp(amount - coin, coins, memo) + 1);
    return memo[amount] = min_coins;
}
