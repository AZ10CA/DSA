class Solution {
public:
    string decodeMessage(string key, string message) {
        // Time: O(n), Space: O(n)
        int idx = 0;
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        unordered_map<char, char> mapping;
        mapping[' '] = ' ';

        for(auto ch: key)
            if(mapping.find(ch) == mapping.end())
                mapping[ch] = alphabet[idx++];

        for(auto& ch: message)
            ch = mapping[ch];


        return message;
    }
};