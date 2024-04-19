class Solution {
public:
    int lengthOfLastWord(string s) {
        // Time: O(n), Space: O(1)
        int length = 0;
        int idx = s.size() - 1;

        while(idx >= 0 && s[idx] == ' ')
            idx--;

        while(idx >= 0 && s[idx] != ' ')
            length++, idx--;

        return length;
    }
};