class Solution {
public:
    int myAtoi(string s) {
        // Time: O(n), Space: O(n)
        string no_space = ignore_ch(s, ' ');
        if(no_space.empty())
            return 0;

        int sign = no_space[0] == '-' ? -1 : 1;
        if(no_space[0] == '+' || no_space[0] == '-')
            no_space = no_space.substr(1);

        string digits = read_digits(no_space);
        if(digits.empty())
            return 0;

        if(digits.size() > 10)
            return sign > 0 ? INT_MAX : INT_MIN;

        return round(digits, sign);
    }

    int round(const string& digits, int sign){
        long long number = std::stoll(digits) * sign;
        number = std::max(INT_MIN * 1ll, number);
        number = std::min(INT_MAX * 1ll, number);

        return number;
    }

    string ignore_ch(const string& str, char ch){
        int idx = 0;
        while(idx < str.size() && str[idx] == ch)
            idx++;

        return str.substr(idx);
    }

    string read_digits(const string& str){
        string result;
        int idx = 0;
        while(std::isdigit(str[idx]) && idx < str.size())
            result += str[idx++];

        return ignore_ch(result, '0');
    }
};