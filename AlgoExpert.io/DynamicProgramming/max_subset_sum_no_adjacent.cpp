#include <vector>

using namespace std;

int dp(int allowed, int idx, const vector<int> &array, vector<vector<int>> &memo) {
    if (idx == array.size())
        return 0;

    auto &m = memo[idx][allowed];
    if (m != -1)
        return m;

    int take = 0;
    if (allowed)
        take = dp(false, idx + 1, array, memo) + array[idx];
    int skip = dp(true, idx + 1, array, memo);

    return m = std::max(skip, take);
}

int maxSubsetSumNoAdjacent(vector<int> array) {
    // Time: O(n), Space: O(n)
    vector<vector<int>> memo(array.size(), vector<int>(2, -1));
    return dp(true, 0, array, memo);
}
