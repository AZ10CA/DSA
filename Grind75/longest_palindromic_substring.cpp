class Solution {
public:
    string longestPalindrome(string s) {
        // Time: O(n^2), Space: O(n)
        string longest;

        for(int i = 0; i < s.size(); i++){
            // expansion with a single letter
            int left = i, right = i;
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                int size = right - left + 1;
                if(size > longest.size())
                    longest = s.substr(left, size);
                left--;
                right++;
            }

            // expansion after pairing
            if(i < s.size() - 1 && s[i] == s[i + 1]){
                int left = i, right = i + 1;
                while(left >= 0 && right < s.size() && s[left] == s[right]){
                    int size = right - left + 1;
                    if(size > longest.size())
                        longest = s.substr(left, size);
                    left--;
                    right++;
                }
            }
        }

        return longest;
    }
};