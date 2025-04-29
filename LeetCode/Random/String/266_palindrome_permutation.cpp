class Solution {
public:
    bool canPermutePalindrome(string s) {
        // Time: O(n), Space: O(1)
        array<int, 26> ft;
        for(auto letter: s)
            ft[letter - 'a']++;


        bool found_odd = false;
        for(auto each: ft){
            if(each % 2 == 0)
                continue;
            else{
                if(found_odd == true)
                    return false;
                found_odd = true;
            }
        }

        return true;
    }
};