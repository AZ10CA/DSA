class Solution {
public:
    bool isPalindrome(string s) {
        // Time: O(n), Space: O(1)

        int left = 0, right = s.size() - 1;

        while(left < right){
            if(!std::isalnum(s[left])){
                left++;
                continue;
            }

            if(!std::isalnum(s[right])){
                right--;
                continue;
            }

            if(std::tolower(s[left]) != std::tolower(s[right]))
                return false;

            left++, right--;
        }

        return true;
    }
};