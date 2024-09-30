class Solution {
public:
    vector<string> uncommonFromSentences(string& s1, string& s2) {
        // Time: O(m+n), Space: O(m+n)
        cin.tie(nullptr);
        cout.tie(nullptr);
        std::ios::sync_with_stdio(false);

        auto first = split(s1), second = split(s2);

        vector<string> result;

        for(const auto&[str, cnt]: first)
            if(cnt == 1 && second.find(str) == second.end())
                result.push_back(str);
            else
                second.erase(str);

        for(const auto&[str, cnt]: second)
            if(cnt == 1)
                result.push_back(str);


        return result;

    }

    unordered_map<string, int> split(const string& str){
        int idx = 0;
        string current_word;
        unordered_map<string, int> result;

        while(idx < str.size()){
            auto letter = str[idx];
            if(letter == ' '){
                result[current_word]++;
                current_word.clear();
            } else
                current_word += letter;
            idx++;
        }

        result[current_word]++;

        result.erase("");
        return result;
    }
};