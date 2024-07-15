class Solution {
public:
    string getSmallestString(string s) {
        // Time: O(n), Space: O(1)
        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] > s[i + 1] && (s[i] & 1) == (s[i + 1] & 1)){
                std::swap(s[i], s[i + 1]);
                i += 2;
                break;
            }
        }

        return s;
    }
};