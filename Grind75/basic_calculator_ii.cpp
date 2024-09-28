class Solution {
public:
    int calculate(string s) {
        // Time: O(n), Space: O(n)
        char last_sign = '+';
        int current_number = 0;

        stack<int> operands;
        s.push_back('+');

        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ')
                continue;

            auto current_char = s[i];
            if(isdigit(current_char))
                current_number = current_number * 10 + (current_char - '0');
            else {
                if(last_sign == '+' || last_sign == '-')
                    operands.push((last_sign == '-' ? -1 : 1) * current_number);
                else {
                    auto top = operands.top();
                    operands.pop();
                    auto result = last_sign == '*' ? top * current_number : top / current_number;
                    operands.push(result);
                }

                last_sign = current_char;
                current_number = 0;
            }
        }

        int result = 0;
        while(!operands.empty()){
            result += operands.top();
            operands.pop();
        }

        return result;
    }
};