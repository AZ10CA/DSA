class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        // Time: O(n), Space: O(n)
        unordered_map<int, int> table;
        for(auto& d: dominoes){
            std::sort(d.begin(), d.end());
            table[d[0] + d[1] * 10]++;
        }

        int pairs = 0;
        for(auto&[key, count]: table)
            pairs += count * (count - 1) / 2;

        return pairs;
    }
};