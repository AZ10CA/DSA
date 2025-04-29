class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // Time: O(n + m), Space: O(n)
        unordered_map<char, int> s1ft;
        for(auto letter: s1)
            s1ft[letter]++;

        unordered_map<char, int> window_ft;
        std::list<char> window;

        for(int i = 0; i < s2.size(); i++){
            if(window.size() < s1.size()){
                window.push_back(s2[i]);
                window_ft[s2[i]]++;
            }

            if(window.size() == s1.size()){
                // check to see if it is a valid permutation
                bool isValid = true;
                for(auto&[letter, frequency]: window_ft){
                    if(frequency == 0)
                        continue;
                    // the letter is not in s1
                    if(s1ft.find(letter) == s1ft.end() || s1ft[letter] != frequency){
                        // remove the left-most letter
                        auto left_ch = window.front();
                        window.pop_front();
                        window_ft[left_ch]--;
                        isValid = false;
                        break;
                    }
                }
                if(isValid)
                    return true;
            }
        }

        return false;
    }
};