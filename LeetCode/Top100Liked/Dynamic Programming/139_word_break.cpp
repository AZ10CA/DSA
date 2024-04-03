class Solution {
    unordered_map<string, bool> memo;
public:
    bool dp(string word, const unordered_set<string>& dict){
        if(word.empty())
            return true;

        if(memo.find(word) != memo.end())
            return memo[word];

        for(int i = 0; i < word.size(); i++){
            auto sub = word.substr(0, i + 1);
            if(dict.find(sub) != dict.end() && dp(word.substr(i + 1), dict))
                return memo[word] = true;
        }

        return memo[word] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        // Time: O(n ^ 2 * m)Space: O(n + m)
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return dp(s, dict);
    }
};