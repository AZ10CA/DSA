class Solution {
public:
    int countSegments(string s) {
        // Time: O(n), Space: O(1)
        int cnt = 0;
        bool is_reading_word = false;

        for(auto ch: s){
            if(ch == ' '){
                cnt += is_reading_word;
                is_reading_word = false;
            } else is_reading_word = true;
        }

        return cnt + is_reading_word;
    }
};