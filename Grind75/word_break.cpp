class Solution {
    vector<int> table;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Time: O(nmk), Space: O(n), n: s.size(), m: wordDict.size(), k: average size of words in wordDict
        table = vector<int>(s.size(), -1);
        return can_make(0, s, wordDict);
    }

    bool can_make(int idx, const string& s, const vector<string>& wordDict){
        if(idx == s.size())
            return true;

        auto& memo = table[idx];
        if(memo != -1)
            return memo;

        for(auto word: wordDict){
            if(can_form(s, idx, word) && can_make(idx + word.size(), s, wordDict))
                return memo = true;
        }

        return memo = false;
    }

    bool can_form(const string& original, int from, const string& with){
        int index = 0;
        for(int i = from; i < original.size() && index < with.size(); i++){
            if(original[i] != with[index])
                return false;
            index++;
        }

        return index == with.size();
    }
};