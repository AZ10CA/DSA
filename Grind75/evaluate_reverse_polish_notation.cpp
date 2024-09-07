class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // Time: O(n), Space: O(n)
        stack<int> nums;
        for(auto token: tokens){
            if(is_operator(token)){
                auto second = nums.top(); nums.pop();
                auto first = nums.top(); nums.pop();
                auto result = process(first, second, token[0]);
                nums.push(result);
            } else nums.push(stoi(token));
        }

        return nums.top();
    }

    bool is_operator(const string& str){
        auto ch = str[0];
        return str.length() == 1 && (ch == '+' || ch == '-' || ch == '/' || ch == '*');
    }

    int process(int first, int second, char op){
        switch(op){
            case '+':
                return first + second;
            case '-':
                return first - second;
            case '*':
                return first * second;
            case '/':
                return first/ second;
            default:
                return 0;
        }
    }
};