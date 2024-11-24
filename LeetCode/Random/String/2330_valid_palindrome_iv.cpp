class Solution {
public:
    bool makePalindrome(string s) {
        // Time: O(n), Space: O(1)
        int left = 0, right = s.size() - 1;
        int operations = 0;
        while(left < right){
            if(s[left] != s[right])
                operations++;
            left++;
            right--;
        }


        return operations <= 2;
    }
};