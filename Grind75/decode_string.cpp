class Solution {
public:
    string decodeString(string s) {
        // Time: O(n), Space: O(n)
        string current;
        string multiplier;

        stack<int> muls;
        stack<string> strs;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '['){
                muls.push(stoi(multiplier));
                strs.push(current);

                current.clear();
                multiplier.clear();
            } else if(s[i] == ']') {
                string builder = strs.top();  // retrieve string outside the brackets
                int count = muls.top();       // retrieve multiplier

                muls.pop();
                strs.pop();

                while(count--)
                    builder += current;
                current = builder;
            } else if(std::isdigit(s[i])){
                multiplier += s[i];
            } else /* is character */ {
                current += s[i];
            }
        }

        return current;
    }
};