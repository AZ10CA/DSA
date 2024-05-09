class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        // Time: O(n * k), Space: O(n * k)
        unordered_map<string, int> ft; // frequency table
        auto cnt = 0;

        for(auto word: words){
            bucket_sort(word);
            ft[word]++;
        }

        for(auto&[word, frequency]: ft)
            cnt += frequency / 2;

        return cnt;

    }

    void bucket_sort(string& str){
        vector<int> chars(26);
        for(auto ch: str)
            chars[ch - 'a']++;

        int idx = 0;
        int writer_idx = 0;
        while(idx < 26){
            for(int i = 0; i < chars[idx]; i++)
                str[writer_idx++] = 'a' + idx;
            idx++;
        }
    }
};