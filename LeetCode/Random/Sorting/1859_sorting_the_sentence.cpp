class Solution {
public:
    string sortSentence(string s) {
        // Time: O(n), Space: O(n)
        vector<string> sorted(10);
        string current;
        for(int i = 0; i < s.size(); i++){
            auto ch = s[i];
            if(ch == ' '){
                auto index = current[current.size() - 1] - '0' - 1;
                current.pop_back();
                sorted[index] = current;
                current = "";
            } else current += ch;
        }

        auto index = current[current.size() - 1] - '0' - 1;
        current.pop_back();
        sorted[index] = current;

        string result;
        for(auto word: sorted)
            if(not word.empty())
                result += word + ' ';

        result.pop_back();
        return result;
    }
};