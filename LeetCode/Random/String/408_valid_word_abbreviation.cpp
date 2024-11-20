class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        // Time: O(n + m), Space: O(1)
        int word_ptr = 0, abbr_ptr = 0;
        while(word_ptr < word.size() && abbr_ptr < abbr.size()){
            if(std::isdigit(abbr[abbr_ptr])){
                int number = 0;
                while(isdigit(abbr[abbr_ptr])){
                    int initial = number;
                    number = number * 10 + (abbr[abbr_ptr] - '0');
                    if(number == initial)
                        return false;
                    abbr_ptr++;
                }


                word_ptr += number;
                continue;
            }

            if(word[word_ptr] != abbr[abbr_ptr])
                return false;

            abbr_ptr++;
            word_ptr++;
        }

        return word_ptr == word.size() && abbr_ptr == abbr.size();
    }
};