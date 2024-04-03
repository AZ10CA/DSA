class Solution {
public:
    bool isSubsequence(string s, string t) {
        // Time: O(n), Space: O(1) where n is the length of the second word
        auto idx = 0;

        for(auto ch: t)
            if(idx < s.size() && s[idx] == ch)
                idx++;

        return idx == s.size();
    }
};