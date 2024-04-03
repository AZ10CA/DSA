class Solution {
    // states: first idx, second idx
    vector<vector<int>> memo;
public:
    int dp(int fp, int sp, const string &fw, const string &sw) {
        if (fp == fw.size() || sp == sw.size())
            return 0;

        auto &m = memo[fp][sp];
        if (m != -1)
            return m;

        // options:
        auto move_both = fw[fp] == sw[sp] ? 1 + dp(fp + 1, sp + 1, fw, sw) : INT_MIN;
        auto skip_fw = dp(fp + 1, sp, fw, sw);
        auto skip_sw = dp(fp, sp + 1, fw, sw);

        return m = std::max(std::max(skip_fw, skip_sw), move_both);

    }

    int longestCommonSubsequence(string text1, string text2) {
        // Time & Space: O(mn) where m: text1.length and n: text2.length
        memo = vector<vector<int>> (text1.size(), vector<int>(text2.size(), -1));
        return dp(0, 0, text1, text2);
    }
};