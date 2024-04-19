class Solution {
public:
    string intToRoman(int num) {
        // Time: O(1), Space: O(1)
        const vector<int> denoms = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const vector<string> characters = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int idx = 0;
        string result;

        while(idx != denoms.size()){
            auto denom = denoms[idx];
            if(num >= denom){
                int count = num / denom;
                num %= denom;
                while(count--)
                    result += characters[idx];
            }
            idx++;
        }

        return result;
    }
};