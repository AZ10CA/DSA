class Solution {
public:
    int characterReplacement(string s, int k) {
        // Time: O(n), Space: O(1)
        string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int answer = 0;

        for(auto letter: alpha){
            int len = max_length(letter, k, s);
            answer = std::max(answer, len);
        }

        return answer;
    }

    int max_length(int ch, int k, const string& str){
        int answer = 0;
        int start = 0; // inclusive
        int end = 0; // exclusive

        while(end < str.size()){
            if(str[end] == ch)
                end++;
            else if(k > 0){
                k--;
                end++;
            } else if(str[start] == ch)
                start++;
            else {
                start++;
                k++;
            }

            answer = std::max(answer, end - start);
        }

        return answer;
    }
};