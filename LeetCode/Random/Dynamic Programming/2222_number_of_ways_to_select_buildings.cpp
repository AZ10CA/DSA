class Solution {
    vector<vector<vector<long long>>> table;
public:
    long long numberOfWays(string s) {
        // idx, last, size
        table = vector<vector<vector<long long>>>(s.size(), vector<vector<long long>>(2, vector<long long>(3, -1)));
        return dp(0, '1', 0, s) + dp(0, '0', 0, s);
    }

    long long dp(int idx, char last, int size, const string& str){
        if(size == 3)
            return 1;

        if(idx == str.size())
            return 0;

        auto& memo = table[idx][last - '0'][size];
        if(memo != -1)
            return memo;

        auto take = last != str[idx] ? dp(idx + 1, str[idx], size + 1, str) : 0;
        auto skip = dp(idx + 1, last, size, str);

        return memo = take + skip;
    }
};