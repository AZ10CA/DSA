class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // Time: O(n), Space: O(n)
        stack<pair<int, int>> st; // index, parenthesis
        unordered_set<int> to_erase; // indices to be removed

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(is_letter(ch))
                continue;

            if(ch == '(')
                st.emplace(i, ch);
            else {
                if(st.empty())
                    to_erase.insert(i);
                else
                    st.pop();
            }
        }

        while(!st.empty()){
            auto top = st.top();
            st.pop();

            to_erase.insert(top.first);
        }

        string result;
        for(int i = 0; i < s.size(); i++){
            if(is_letter(s[i]) || to_erase.find(i) == to_erase.end())
                result.push_back(s[i]);
        }

        return result;
    }

    bool is_letter(char ch){
        return ch != '(' && ch != ')';
    }
};