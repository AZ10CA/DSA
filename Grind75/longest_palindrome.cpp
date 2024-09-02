class Solution {
public:
    int longestPalindrome(string s) {
        // Time: O(n), Space: O(1)
        int answer = 0;
        unordered_map<char, int> ft; // frequency table

        for(auto ch: s)
            ft[ch]++;

        int max_odd = 0;
        bool has_odd = false;

        for(auto&[ch, cnt]: ft)
            if(cnt % 2 == 0)
                answer += cnt;
            else {
                has_odd = true;
                answer += cnt - 1;
            }


        return answer + has_odd;
    }
};