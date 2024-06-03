class Solution {
public:
    int firstUniqChar(string s) {
        // Time: O(n), Space: O(1)
        unordered_map<char, int> indices;
        unordered_map<char, int> ft;
        for(int i = 0; i < s.size(); i++){
            auto ch = s[i];
            indices[ch] = i;
            ft[ch]++;
        }

        int answer = INT_MAX;

        for(auto& [ch, frequency]: ft)
            if(frequency == 1)
                answer = std::min(answer, indices[ch]);

        return answer == INT_MAX ? -1 : answer;
    }
};