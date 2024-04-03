class Solution {
public:
    string reverseVowels(string s) {
        // Time: O(n), Space: O(1)
        int fp = 0, sp = s.size() - 1;
        while(fp < sp){
            if(!isVowel(s[fp])){
                fp++;
                continue;
            }

            if(!isVowel(s[sp])){
                sp--;
                continue;
            }
            std::swap(s[fp++], s[sp--]);
        }

        return s;
    }

    bool isVowel(char c){
        vector<char> vowels = {'a', 'e', 'o', 'u', 'i', 'A', 'I', 'O', 'E', 'U'};
        for(auto each: vowels)
            if(each == c)
                return true;

        return false;
    }
};