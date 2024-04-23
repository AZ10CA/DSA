class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Time: O(n), Space: O(m), m: number unique characters in "s"
        unordered_map<char, char> mapping;

        for(int i = 0; i < s.size(); i++){
            auto from = s[i], to = t[i];
            if(mapping.find(from) == mapping.end())
                mapping[from] = to;
            else if(mapping[from] != to)
                return false;
        }

        return true;
    }
};