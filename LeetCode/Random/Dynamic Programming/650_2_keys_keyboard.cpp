class Solution {
    vector<vector<int>> table;
public:
    int minSteps(int n) {
        // Time: O(n^2), Space: O(n^2)
        cin.tie(nullptr);
        cout.tie(nullptr);
        std::ios::sync_with_stdio(false);

        table = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));

        return dp(1, 0, n);
    }

    int dp(int size, int copy_size, int n){
        if(size == n)
            return 0;

        if(size > n)
            return n;

        auto& memo = table[size][copy_size];
        if(memo != -1)
            return memo;

        auto copy_paste = dp(size + size, size, n) + 2;
        auto paste = copy_size > 0 ? dp(size + copy_size, copy_size, n) + 1 : n;

        return memo = std::min(copy_paste, paste);
    }
};