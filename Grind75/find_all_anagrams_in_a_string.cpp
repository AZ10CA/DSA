class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // Time: O(n), Space: O(1)
        list<char> anagram;
        vector<int> result;

        unordered_map<char, int> p_ft;
        unordered_map<char, int> anagram_ft;

        for(auto letter: p)
            p_ft[letter]++;

        for(int i = 0; i < s.size(); i++){
            anagram.push_back(s[i]);
            anagram_ft[s[i]]++;

            if(anagram.size() < p.size())
                continue;

            if(anagram.size() == p.size()){
                if(is_anagram(anagram_ft, p_ft))
                    result.push_back(i - p.size() + 1);
            } else {
                auto first_letter = anagram.front();
                anagram.pop_front();
                anagram_ft[first_letter]--;
                if(is_anagram(anagram_ft, p_ft))
                    result.push_back(i - p.size() + 1);
            }
        }

        return result;
    }

    bool is_anagram(unordered_map<char, int>& anagram_ft, unordered_map<char, int>& p_ft){
        for(auto&[letter, frequency]: p_ft)
            if(anagram_ft.find(letter) == anagram_ft.end() || frequency != anagram_ft[letter])
                return false;

        return true;
    }
};