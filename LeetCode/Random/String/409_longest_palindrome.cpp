class Solution {
public:
    int longestPalindrome(string s) {
        // Time: O(n), Space: O(n)
        auto length = 0;
        unordered_map<char, int> ft;

        for(auto ch: s)
            ft[ch]++;

        auto odd_count_exists = false;
        for(auto&[ch, count]: ft)
            if(count % 2 == 0)
                length += count;
            else {
                odd_count_exists = true;
                length += count - 1;
            }

        return length + odd_count_exists;
    }
};