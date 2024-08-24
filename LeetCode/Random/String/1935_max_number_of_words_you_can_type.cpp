class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        // Time: O(n), Space: O(1)
        string current_word;
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());

        int result = 0;
        for(int i = 0; i < text.size(); i++){
            auto& letter = text[i];
            if(letter == ' '){
                result += can_type(current_word, broken);
                current_word = "";
            } else current_word += letter;

        }


        return result + can_type(current_word, broken);
    }


    bool can_type(const string& str, const unordered_set<char>& broken){
        if(str.empty())
            return true;
        for(auto letter: str)
            if(broken.find(letter) != broken.end())
                return false;
        return true;
    }

};