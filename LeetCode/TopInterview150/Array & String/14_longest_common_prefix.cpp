class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Time: O(n), Space: O(m) n: sum of characters, m: size of the smallest string
        int idx = 0;
        while(idx < strs[0].size()){
            char current = strs[0][idx];
            for(const auto& str: strs){
                if(str[idx] != current){
                    if(idx == 0)
                        return "";
                    return strs[0].substr(0, idx);
                }
            }
            idx++;
        }
        return strs[0];
    }
};