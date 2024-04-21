class Solution {
public:
    int strStr(string haystack, string needle) {
        // Time: O(nk), Space: O(nk)
        if(needle.size() > haystack.size())
            return -1;

        unordered_map<string, int> positions;

        string current;
        current = haystack.substr(0, needle.size());
        positions[current] = 0;
        for(int i = needle.size(); i < haystack.size(); i++){
            current = current.substr(1);
            current.push_back(haystack[i]);
            if(positions.find(current) == positions.end())
                positions[current] = i - needle.size() + 1;
        }

        if(positions.find(needle) == positions.end())
            return -1;

        return positions[needle];
    }
};