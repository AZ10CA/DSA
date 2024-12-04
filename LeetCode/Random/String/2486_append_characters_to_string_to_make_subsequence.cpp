class Solution {
public:
    int appendCharacters(string s, string t) {
        // Time: O(n), Space: O(1)
        int idx = 0;
        for(int i = 0; i < s.size() && idx < t.size(); i++){
            if(s[i] == t[idx])
                idx++;
        }

        return t.size() - idx;
    }
};