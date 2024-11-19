class Solution {
public:
    string multiply(string num1, string num2) {
        // Time: O(mn), Space: O(mn)
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());

        vector<string> mul_results;
        int power = 0;
        for(auto digit: num1){
            auto mul_result = single_digit_mul(digit - '0', num2);
            for(int i = 0; i < power; i++)
                mul_result.push_back('0');
            power++;
            mul_results.push_back(mul_result);
        }

        string result = "0";
        for(auto num: mul_results)
            result = sum_strings(result, num);

        result = strip_leading_zeroes(result);
        return result.size() ? result : "0";
    }

    string sum_strings(string lhs, string rhs){
        string result;
        std::reverse(lhs.begin(), lhs.end());
        std::reverse(rhs.begin(), rhs.end());
        int size = std::max(lhs.size(), rhs.size());

        bool has_carry = false;
        for(int i = 0; i < size; i++){
            int lhs_digit = i < lhs.size() ? lhs[i] -'0' : 0;
            int rhs_digit = i < rhs.size() ? rhs[i] -'0' : 0;
            int sum = lhs_digit + rhs_digit + has_carry;

            has_carry = sum > 9;
            sum %= 10;

            result.insert(result.begin(), sum + '0');
        }

        if(has_carry)
            result.insert(result.begin(), '1');

        return result;
    }

    string single_digit_mul(int digit, const string& num){ // pass the reversed number
        string answer;
        int carry = 0;

        for(int i = 0; i < num.size(); i++){
            auto _digit = num[i] - '0';
            int result = _digit * digit + carry;
            carry = result / 10;
            result %= 10;
            answer = to_string(result) + answer;
        }

        if(carry)
            answer = to_string(carry) + answer;
        return answer;
    }

    string strip_leading_zeroes(const string& str){
        int i = 0;
        while(str[i] == '0')
            i++;
        return str.substr(i);
    }
};