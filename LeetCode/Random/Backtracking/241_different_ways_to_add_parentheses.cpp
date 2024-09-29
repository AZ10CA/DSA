class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        return backtrack(0, expression.size() - 1, expression);
    }

    vector<int> backtrack(int left, int right, const string& expression){
        vector<int> result;
        for(int i = left; i < right + 1; i++){
            auto ch = expression[i];
            if(is_operator(ch)){
                auto nums1 = backtrack(left, i - 1, expression);
                auto nums2 = backtrack(i + 1, right, expression);
                for(auto num1: nums1)
                    for(auto num2: nums2)
                        result.push_back(process(num1, ch, num2));
            }
        }

        if(result.empty())
            result.push_back(stoi(expression.substr(left, right - left + 1)));


        return result;
    }

    int process(int first, char op, int second){
        switch(op){
            case '-':
                return first - second;
            case '+':
                return first + second;
            case '*':
                return first * second;
            default:
                return 0;
        }
    }

    bool is_operator(char ch){
        return ch == '-' || ch == '+' || ch == '*';
    }
};