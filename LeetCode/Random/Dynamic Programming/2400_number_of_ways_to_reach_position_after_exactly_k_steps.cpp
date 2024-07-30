class Solution {
    const int MOD = 1e9 + 7;
public:
    int numberOfWays(int startPos, int endPos, int k) {
        unordered_map<int, unordered_map<int, int>> table;
        return count(startPos, k, endPos, table);
    }

    int count(int pos, int left, const int end, unordered_map<int, unordered_map<int, int>>& table){
        // Time: O(k), Space: O(k)
        if(left == 0)
            return pos == end;

        if(table.find(pos) != table.end() and table[pos].find(left) != table[pos].end())
            return table[pos][left];

        int go_left = count(pos - 1, left - 1, end, table) % MOD;
        int go_right = count(pos + 1, left - 1, end, table) % MOD;

        return table[pos][left] = (go_left + go_right) % MOD;
    }
};