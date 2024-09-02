class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // Time: O(n + m), Space: O(1) 
        unordered_map<char, int> ft; // frequency_table
        for(auto ch: magazine)
            ft[ch]++;

        for(auto ch: ransomNote)
            ft[ch]--;

        for(auto&[ch, cnt]: ft)
            if(cnt < 0)
                return false;

        return true;
    }
};