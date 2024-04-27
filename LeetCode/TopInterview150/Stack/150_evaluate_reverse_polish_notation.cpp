class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // Time: O(n), Space: O(n)
        stack<int> operands;
        for(auto each: tokens){
            if(is_digit(each))
                operands.push(std::stoi(each));
            else {
                auto second = operands.top(); operands.pop();
                auto first = operands.top(); operands.pop();
                if(each == "-")
                    operands.push(first - second);
                else if(each == "+")
                    operands.push(first + second);
                else if(each == "*")
                    operands.push(first * second);
                else operands.push(first / second);
            }
        }

        return operands.top();
    }

    bool is_digit(string str){
        auto last = str[str.size() - 1];
        return last != '-' && last != '+' && last != '*' && last != '/';
    }
};