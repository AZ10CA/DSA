class Solution {
public:
    unordered_set<char> opening = {'(', '[', '{'};
    unordered_set<char> closing = {')', '}', ']'};

    bool isValid(string s) {
        // Time: O(n), Space: O(n)
        stack<char> st;
        for (auto ch: s) {
            if (opening.find(ch) != opening.end()) {
                st.push(ch);
            } else if (closing.find(ch) != closing.end()) {
                if (st.empty())
                    return false;
                if (!isMatching(st.top(), ch))
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }

    bool isMatching(char first, char second) {
        return first == '(' && second == ')' || first == '{' && second == '}' || first == '[' && second == ']';
    }

};