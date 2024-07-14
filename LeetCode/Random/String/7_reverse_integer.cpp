class Solution {
public:
    int reverse(int x) {
        // Time: O(1), Space: O(1)
        auto sign = x >= 0 ? 1 : -1;
        x = std::abs(x);

        auto str = to_string(x);
        std::reverse(str.begin(), str.end());

        return to_integer(str) * sign;
    }

    int to_integer(const string& str){
        try {
            int result = stoi(str);
            return result;
        } catch(const std::out_of_range& e){
            return 0;
        }
    }
};