class Solution {
public:
    string removeStars(string s) {
        // Time: O(n), Space: O(n)
        string result;
        for(auto ch: s)
            if(ch == '*')
                result.pop_back();
            else
                result.push_back(ch);

        return result;
    }
};