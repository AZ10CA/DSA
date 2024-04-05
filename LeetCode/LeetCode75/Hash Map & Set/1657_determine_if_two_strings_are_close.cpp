class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // Time: O(n), Space: O(1)
        /**
        3 conditions must be met:
        same lengths
        same unique characters in both
        same character count frequencies
        */

        unordered_map<int, int> ft1, ft2; // frequency table
        unordered_set<char> seen;

        // condition 2
        if(word1.size() != word2.size())
            return false;

        for(auto ch: word1){
            seen.insert(ch);
            ft1[ch]++;
        }

        for(auto ch: word2){
            // condition 2
            if(seen.find(ch) == seen.end())
                return false;
            ft2[ch]++;
        }

        // condition 3
        unordered_map<int, int> count_ft; // frequency table of character counts
        for(auto &[ch, count]: ft1)
            count_ft[count]++;

        for(auto &[ch, count]: ft2)
            if(count_ft.find(count) == count_ft.end() || count_ft[count] == 0)
                return false;
            else
                count_ft[count]--;

        return true;
    }
};