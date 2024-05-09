class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // Time: O(n), Space: O(1), n: sum of the number of characters in the words array
        unordered_set<char> allowed_characters(allowed.begin(), allowed.end());
        auto cnt = 0;

        for(auto& word: words)
            cnt += is_word_allowed(word, allowed_characters);

        return cnt;
    }

    bool is_word_allowed(const string& word, const unordered_set<char>& allowed_characters){
        bool result = true;
        for(auto ch: word)
            result &= allowed_characters.find(ch) != allowed_characters.end();

        return result;
    }
};