class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // Time: O(n), Space: O(n)
        string current;
        vector<string> words;
        unordered_map<char, string> mapping;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                words.push_back(current);
                current = "";
            } else
                current += s[i];
        }

        words.push_back(current);

        if(pattern.size() != words.size())
            return false;

        for(int i = 0; i < pattern.size(); i++){
            if(mapping.find(pattern[i]) == mapping.end())
                mapping[pattern[i]] = words[i];
            else if(mapping[pattern[i]] != words[i])
                return false;
        }

        unordered_set<string> seen;
        for(auto&[letter, string]: mapping)
            if(seen.find(string) != seen.end())
                return false;
            else
                seen.insert(string);

        return true;
    }
};