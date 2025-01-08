class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        // Time: O(n), Space: O(1)
        int f_idx = -1, s_idx = -1;
        int ans = INT_MAX;
        for(int i = 0; i < wordsDict.size(); i++){
            auto& word = wordsDict[i];
            if(word == word1)
                f_idx = i;
            else if(word == word2)
                s_idx = i;

            if(f_idx != -1 && s_idx != -1)
                ans = std::min(ans, abs(f_idx - s_idx));
        }

        return ans;
    }
};