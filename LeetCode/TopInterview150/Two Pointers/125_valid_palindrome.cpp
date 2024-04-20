class Solution {
public:
    bool isPalindrome(string s) {
        // Time: O(n), Space: O(1)
        int fp = 0, sp = s.size() - 1;
        while(fp < sp){
            if(!std::isalnum(s[fp])){
                fp++;
                continue;
            }

            if(!std::isalnum(s[sp])){
                sp--;
                continue;
            }

            if(std::tolower(s[fp]) != std::tolower(s[sp]))
                return false;

            fp++;
            sp--;
        }

        return true;
    }
};