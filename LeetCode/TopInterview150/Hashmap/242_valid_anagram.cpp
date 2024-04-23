class Solution {
public:
    bool isAnagram(string s, string t) {
        // Time: O(n + m), Space: O(1)
        bucket_sort(s);
        bucket_sort(t);
        return s == t;
    }

    void bucket_sort(string& s){
        vector<int> ft(26, 0);
        for(auto letter: s)
            ft[letter - 'a']++;

        int idx = 0;

        for(int i = 0; i < ft.size(); i++){
            char letter = 'a' + i;
            for(int j = 0; j < ft[i]; j++)
                s[idx++] = letter;
        }
    }
};