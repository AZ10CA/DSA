class Solution {
public:
    string countAndSay(int n, string str = "1") {
        // Time: O(2^n), Space: O(n)
        if(n == 1)
            return str;

        string result;
        char cur_ch = str[0];
        int count = 0;

        for(int i = 0; i < str.size(); i++){
            if(cur_ch == str[i])
                count++;
            else {
                result += to_string(count);
                result += cur_ch;
                cur_ch = str[i];
                count = 1;
            }
        }

        result += to_string(count);
        result += cur_ch;

        return countAndSay(n - 1, result);
    }
};