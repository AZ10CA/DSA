class Solution {
public:
    pair<string, int> recursiveDecoder(const string& str, int pos){
        // Time: O(n * k), Space: O(n) where k is the average multiplier

        string result;
        int multiplier = 0;

        while(pos < str.size()){
            auto ch = str[pos];
            // is digit
            if(ch >= '0' && ch <= '9'){
                multiplier = multiplier * 10 + (ch - '0');
                pos++;
            } else if(ch == '['){
                auto [nested, new_pos] = recursiveDecoder(str, pos + 1); // skip '['
                while(multiplier > 0){
                    result += nested;
                    multiplier--;
                }
                pos = new_pos;
            } else if(ch == ']') {
                return {result, pos + 1}; // skip ']'
            } else {
                result += ch;
                pos++;
            }
        }

        return {result, pos};
    }

    string decodeString(string s) {
        return recursiveDecoder(s, 0).first;
    }
};