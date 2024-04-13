class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size())
            return {};
        // Time: O(n + m), Space: O(1)
        unordered_map<char, int> p_ft;
        unordered_map<char, int> window;
        vector<int> result;

        for(auto ch: p)
            p_ft[ch]++;

        // set up the window
        for(int i = 0; i < p.size(); i++)
            window[s[i]]++;

        if(isSame(window, p_ft))
            result.push_back(0);

        for(int i = p.size(); i < s.size(); i++){
            auto old_ch = s[i - p.size()];
            auto new_ch = s[i];
            window[old_ch]--;
            if(window[old_ch] == 0)
                window.erase(old_ch);
            window[new_ch]++;
            if(isSame(window, p_ft))
                result.push_back(i - p.size() + 1);
        }

        return result;
    }

    bool isSame(unordered_map<char, int>& first, unordered_map<char, int>& second){
        // Time: O(1), Space: O(1) (26 characters)
        for(const auto&[ch, count]: first){
            if(second.find(ch) == second.end() || second[ch] != count)
                return false;
        }

        return first.size() == second.size();
    }
};