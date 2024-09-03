class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Time: O(nm), Space: O(m), m: length of the common prefix, n: strs.size()
        int pointer = 0;
        char current_letter = strs[0][pointer];

        while(pointer < strs[0].size()){
            for(const auto& str: strs){
                if(pointer == str.size())
                    return str;
                if(str[pointer] != current_letter)
                    return str.substr(0, pointer);
            }
            pointer++;
            current_letter = strs[0][pointer];
        }

        return strs[0].substr(0, pointer);
    }
};