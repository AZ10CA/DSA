class Solution {
public:
    int romanToInt(string s) {
        // Time: O(n), Space: O(1)
        unordered_map<char, int> map = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
        };

        int result = 0;
        int left;

        for(int i = 0; i < s.size(); i++){
            left = i == 0 ? INT_MAX : map[s[i - 1]];
            auto current = map[s[i]];
            result += current;

            if(current > left)
                result -= 2 * left;

            left = current;
        }

        return result;
    }
};