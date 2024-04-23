class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // Time: O(n + m), Space: O(n)
        unordered_map<char, int> ft;
        for(auto letter: ransomNote)
            ft[letter]++;

        for(auto letter: magazine)
            if(ft.find(letter) == ft.end())
                continue;
            else
                ft[letter]--;


        for(auto&[letter, count]: ft)
            if(count > 0)
                return false;


        return true;
    }
};