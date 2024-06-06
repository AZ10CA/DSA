class Solution {
public:
    string addStrings(string num1, string num2) {
        // Time: O(n + m), Space: O(n + m)
        num1.insert(num1.begin(), '0');
        num2.insert(num2.begin(), '0');
        auto max_length = std::max(num1.size(), num2.size());

        while(num1.size() != max_length)
            num1.insert(num1.begin(), '0');

        while(num2.size() != max_length)
            num2.insert(num2.begin(), '0');

        string result;
        bool has_carry = false;
        for(int i = max_length - 1; i >= 0; i--){
            int sum = num1[i] + num2[i] + has_carry - 2 * '0';
            has_carry = false;
            has_carry = sum > 9;

            sum %= 10;

            result.insert(result.begin(), sum + '0');
        }

        if(result[0] == '0')
            result.erase(result.begin());

        return result;
    }
};