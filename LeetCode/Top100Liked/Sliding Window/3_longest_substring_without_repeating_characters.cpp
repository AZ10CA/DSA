class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Time: O(n), Space: O(m) m: count of unique characters
        list<char> window;
        unordered_set<char> seen;
        int result = 0;

        for(int i = 0; i < s.size(); i++){
            auto ch = s[i];
            if(seen.find(ch) == seen.end()){
                window.push_back(ch);
                seen.insert(ch);
            } else {
                auto ptr = window.begin();
                while(*ptr != ch){
                    seen.erase(*ptr);
                    ptr++;
                    window.pop_front();
                }
                window.pop_front();
                window.push_back(ch);
            }

            result = std::max(result, (int)seen.size());
        }
        return result;

    }
};