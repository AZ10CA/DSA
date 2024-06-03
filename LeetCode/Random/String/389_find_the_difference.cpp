class Solution {
public:
    char findTheDifference(string s, string t) {
        // Time: O(n), Space: O(n)
        unordered_map<char, int> ft;

        for(auto ch: s)
            ft[ch]++;

        for(auto ch: t)
            ft[ch]--;

        for(auto& [ch, frequency]: ft)
            if(frequency != 0)
                return ch;

        return 42;
    }
};