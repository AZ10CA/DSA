class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // Time: O(n), Space: O(1)
        vector<int> result;
        unordered_map<char, int> p_ft;
        unordered_map<char, int> anagram_ft;

        for(auto letter: p)
            p_ft[letter]++;

        int size = 0;
        for(int i = 0; i < s.size(); i++){
            size++;
            anagram_ft[s[i]]++;

            if(size < p.size())
                continue;

            if(size == p.size()){
                if(is_anagram(anagram_ft, p_ft))
                    result.push_back(i - p.size() + 1);
            } else {
                auto first_letter = s[i - size + 1];
                size--;
                anagram_ft[first_letter]--;
                if(is_anagram(anagram_ft, p_ft))
                    result.push_back(i - p.size() + 1);
            }
        }

        return result;
    }

    bool is_anagram(unordered_map<char, int>& anagram_ft, unordered_map<char, int>& p_ft){
        // Time: O(1), Space: O(1)
        for(auto&[letter, frequency]: p_ft)
            if(anagram_ft.find(letter) == anagram_ft.end() || frequency != anagram_ft[letter])
                return false;

        return true;
    }
};