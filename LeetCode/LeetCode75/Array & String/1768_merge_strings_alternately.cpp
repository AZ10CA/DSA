class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        // Time: O(n + m), Space: O(n + m)
        int fi = 0, si = 0;
        string result;
        while(fi < word1.size() || si < word2.size()){
            if(fi < word1.size())
                result += word1[fi++];
            if(si < word2.size())
                result += word2[si++];
        }

        return result;
    }
};