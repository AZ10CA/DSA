class Solution {
public:
    int minDistance(string word1, string word2) {
        // Time: O(mn), Space: O(mn)
        vector<vector<int>> table(word1.size(), vector<int>(word2.size(), - 1));
        return traverse(word1.size() - 1, word2.size() - 1, word1, word2, table);
    }

    int traverse(int fi, int si, const string& first, const string& second, vector<vector<int>>& table){
        if(fi < 0)
            return si + 1;
        if(si < 0)
            return fi + 1;

        auto& memo = table[fi][si];
        if(memo != -1)
            return memo;

        if(first[fi] == second[si])
            return memo = traverse(fi - 1, si - 1, first, second, table);
        else {
            auto del_first = traverse(fi - 1, si, first, second, table);
            auto del_second = traverse(fi, si - 1, first, second, table);
            return memo = std::min(del_first, del_second) + 1;
        }
    }
};