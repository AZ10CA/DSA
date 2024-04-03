class Solution {
public:
    string longestPalindrome(string s) {
        // Time: O(n^2), Space: O(1)
        pair<int, int> current = {0, 0};
        for (int i = 0; i < s.size(); i++) {
            int left = i, right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                if (current.second - current.first + 1 < right - left + 1)
                    current = {left, right};
                left--;
                right++;
            }
        }

        for (int i = 0; i < s.size(); i++) {
            int left = i, right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                if (current.second - current.first + 1 < right - left + 1)
                    current = {left, right};
                left--;
                right++;
            }
        }


        return s.substr(current.first, current.second - current.first + 1);
    }
};