class Solution {
public:
    int minSteps(string s, string t) {
        // Time: O(n), Space: O(n)
        unordered_map<char, int> ft;
        int result = 0;
        for(auto ch: s)
            ft[ch]++;

        for(auto ch: t)
            ft[ch]--;

        for(auto& [ch, cnt]: ft)
            result += std::max(0, cnt);


        return result;
    }
};