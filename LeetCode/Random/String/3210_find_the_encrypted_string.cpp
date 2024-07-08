class Solution {
public:
    string getEncryptedString(string s, int k) {
        // Time: O(n), Space: O(n)
        string result = s;

        for(int i = 0; i < s.size(); i++)
            result[i] = s[(i + k) % s.size()];

        return result;
    }
};