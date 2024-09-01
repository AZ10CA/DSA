class Solution {
public:
    bool isAnagram(string s, string t) {
        return solution_2(s, t);
    }

    bool solution_1(string& s, string& t){
        // Time: O(nlogn), Space: O(1)
        if(s.size() != t.size())
            return false;

        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        return s == t;
    }

    bool solution_2(string& s, string& t){
        // Time: O(n), Space: O(n)
        if(s.size() != t.size())
            return false;

        unordered_map<char, int> ft; // frequency table

        for(int i = 0; i < s.size(); i++){
            ft[s[i]]++;
            ft[t[i]]--;
        }

        for(auto&[ch, cnt]: ft)
            if(cnt != 0)
                return false;

        return true;
    }
};