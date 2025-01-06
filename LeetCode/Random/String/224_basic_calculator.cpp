class Solution {
public:
    Solution(){
        cin.tie(nullptr);
        cout.tie(nullptr);
        std::ios::sync_with_stdio(false);
    }

    int calculate(string s) {
        int idx = 0;
        return evaluate(idx, "(" + s + ")");
    }

    int evaluate(int& from, const string& str){
        // Time: O(n), Space: O(n)
        // starts evaluating starting from the "from" idx and then updates it to point to the character after the closing parenthesis
        // returns the result of the calculation
        int sum = 0;
        char oper = '+';
        int iterator = from + 1;
        int current_num = 0;

        while(iterator < str.size()){
            if(str[iterator] == ' '){
                iterator++;
                continue;
            }

            if(std::isdigit(str[iterator])){
                current_num = current_num * 10ll + str[iterator] - '0';
                iterator++;
            } else if(str[iterator] == '('){
                auto nested_sum = evaluate(iterator, str);
                sum = process(sum, oper, nested_sum);
            } else if(str[iterator] == ')') {
                from = iterator + 1;
                return process(sum, oper, current_num);
            } else {
                // is an operator
                sum = process(sum, oper, current_num);
                current_num = 0;
                oper = str[iterator];
                iterator++;
            }
        }

        from = iterator;
        return process(sum, oper, current_num);
    }

    int process(int left, char oper, int right){
        return oper == '-' ? left - right : left + right;
    }
};