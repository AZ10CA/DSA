class Solution {
public:
    string addBinary(string a, string b) {
        // Time: O(n + m), Space: O(n + m)
        bool has_one = false;
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());

        auto& larger = a.size() > b.size() ? a : b;


        for(int i = 0; i < larger.size(); i++){
            auto first_digit = i >= a.size() ? 0 : a[i] - '0';
            auto second_digit = i >= b.size() ? 0 : b[i] - '0';

            auto result = has_one + first_digit + second_digit;
            has_one = result >= 2;
            result %= 2;

            larger[i] = result + '0';
        }

        if(has_one)
            larger.push_back('1');

        std::reverse(larger.begin(), larger.end());

        return larger;
    }
};