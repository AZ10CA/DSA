class Solution {
public:
    int maxVowels(string s, int k) {
        // Time: O(n), Space: O(1)
        int vowel_count = 0;
        int max_vowels = 0;
        for(int i = 0; i < k; i++){
            if(isVowel(s[i]))
                vowel_count++;
        }

        max_vowels = vowel_count;

        for(int i = k; i < s.size(); i++){
            vowel_count = vowel_count - isVowel(s[i - k]) + isVowel(s[i]);
            max_vowels = std::max(max_vowels, vowel_count);
        }

        return max_vowels;
    }

    bool isVowel(char c){
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        return std::any_of(vowels.begin(), vowels.end(), [&](char ch){
            return ch == c;
        });
    }
};