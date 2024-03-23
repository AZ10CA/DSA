using namespace std;

int dp(int idx1, int idx2, const string &first, const string &second, vector <vector<int>> &memo) {
    if (idx1 == first.size())
        return second.size() - idx2;

    if (idx2 == second.size())
        return first.size() - idx1;

    if (first[idx1] == second[idx2])
        return dp(idx1 + 1, idx2 + 1, first, second, memo);

    auto &m = memo[idx1][idx2];
    if (m != -1)
        return m;

    return m = std::min(
            dp(idx1 + 1, idx2 + 1, first, second, memo),
            std::min(
                    dp(idx1 + 1, idx2, first, second, memo),
                    dp(idx1, idx2 + 1, first, second, memo)
            )
    ) + 1;
}

int levenshteinDistance(string str1, string str2) {
    // Time: O(mn), Space: O(mn)
    vector <vector<int>> memo(str1.size(), vector<int>(str2.size(), -1));
    return dp(0, 0, str1, str2, memo);
}
