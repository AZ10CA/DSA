class Solution {
public:
    bool isValid(string s) {
        // Time: O(n), Space: O(n)
        stack<char> brackets;

        for(auto ch: s){
            if(isOpening(ch))
                brackets.push(ch);
            else {
                if(brackets.empty())
                    return false;
                auto top = brackets.top();
                brackets.pop();
                if(not isMatching(top, ch))
                    return false;
            }
        }

        return brackets.empty();
    }

    bool isOpening(char ch){
        return ch == '(' or ch == '[' or ch == '{';
    }

    bool isClosing(char ch){
        return ch == ']' or ch == ')' or ch == '}';
    }

    bool isMatching(char left, char right){
        if(not isOpening(left) or not isClosing(right))
            return false;

        return left == '[' and right == ']' or left == '(' and right == ')' or left == '{' and right == '}';
    }
};