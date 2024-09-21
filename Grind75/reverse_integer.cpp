class Solution {
public:
    int reverse(int x) {
        string str = to_string(x);
        int sign = str[0] == '-' ? -1 : 1;

        if(sign < 0)
            str.erase(str.begin());

        std::reverse(str.begin(), str.end());

        int result = 0;
        for(int i = 0; i < str.size(); i++){
            if(result > INT_MAX / 10)
                return 0;
            result *= 10;
            auto digit = str[i] - '0';
            if(result > INT_MAX - digit)
                return 0;
            result += digit;
        }

        return result * sign;
    }
};