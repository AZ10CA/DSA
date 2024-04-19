class Solution {
public:
    int romanToInt(string s) {
        // Time: O(n), Space: O(1)
        unordered_map<char, int> to_num = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int prev_num = INT_MAX;
        int sum = 0;

        for(int i = 0; i < s.size(); i++){
            auto num = to_num[s[i]];
            if(num <= prev_num){
                sum += num;
                prev_num = num;
            } else {
                sum += num - 2 * prev_num;
                prev_num = INT_MAX;
            }
        }

        return sum;
    }
};