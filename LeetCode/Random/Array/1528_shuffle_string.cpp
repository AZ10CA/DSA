class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        // Time: O(n), Space: O(n)
        string result = s;
        for(int i = 0; i < indices.size(); i++)
            result[indices[i]] = s[i];

        return result;
    }
};