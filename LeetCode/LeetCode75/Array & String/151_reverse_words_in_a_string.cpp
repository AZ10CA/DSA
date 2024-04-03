class Solution {
public:
    string reverseWords(string s) {
        // Time: O(n), Space: O(n)
        string result;
        string current_word;
        vector<string> words;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                if(current_word.size()){
                    words.push_back(current_word);
                    current_word = "";
                }
            } else {
                current_word += s[i];
            }
        }

        if(current_word.size())
            words.push_back(current_word);

        std::reverse(words.begin(), words.end());
        for(int i = 0; i < words.size(); i++)
            result += (i == 0 ? "" : " ") + words[i];

        return result;
    }
};