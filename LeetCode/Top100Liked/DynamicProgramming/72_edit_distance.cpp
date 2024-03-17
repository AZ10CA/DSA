class Solution {
public:
    vector<vector<int>> memo;

    int minDistance(string word1, string word2) {
        // Time & Space: O(nm)
        memo = vector<vector<int>>(word1.size(), vector<int>(word2.size(), -1));
        return dp(word1, word2, 0, 0);
    }

    int dp(const string& w1, const string& w2, int i, int j){
        if(i == w1.size() && j == w2.size())
            return 0;
        if(i == w1.size())
            return w2.size() - j;
        if(j == w2.size())
            return w1.size() - i;
        if(w1[i] == w2[j])
            return dp(w1, w2, i + 1, j + 1);

        if(memo[i][j] != -1)
            return memo[i][j];

        auto insert = dp(w1, w2, i + 1, j) + 1;
        auto replace = dp(w1, w2, i + 1, j + 1) + 1;
        auto del = dp(w1, w2, i, j + 1) + 1;

        return memo[i][j] = std::min(del, std::min(insert, replace));
    }
};