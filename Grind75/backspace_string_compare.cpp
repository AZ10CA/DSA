class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return solution_2(s, t);
    }

    bool solution_1(const string& s, const string& t){
        // Time: O(n + m), Space: O(n + m)
        return make_stack(s) == make_stack(t);
    }

    bool solution_2(string& s, string& t){
        // Time: O(n), Space: O(1)
        std::reverse(s.begin(), s.end());
        std::reverse(t.begin(), t.end());

        int s_idx = 0, t_idx = 0;

        while(s_idx < s.size() || t_idx < t.size()){
            while(next(s_idx, s) == '#');
            while(next(t_idx, t) == '#');

            auto ch1 = next(s_idx, s);
            auto ch2 = next(t_idx, t);

            if(ch1 != ch2)
                return false;

            s_idx++;
            t_idx++;
        }

        return true;
    }

    char next(int& idx, const string& str){
        if(idx >= str.size())
            return NULL;

        auto current_letter = str[idx];
        if(current_letter != '#')
            return current_letter;

        int cnt = 1;
        idx++;
        while(cnt != 0 && idx < str.size()){
            if(str[idx] == '#')
                cnt++;
            else
                cnt--;
            idx++;
        }

        idx = std::min((int)str.size(), idx);

        return idx == str.size() ? NULL : str[idx];
    }

    stack<char> make_stack(const string& str){
        stack<char> st;
        for(auto letter: str){
            if(letter != '#')
                st.push(letter);
            else if(!st.empty())
                st.pop();
        }

        return st;
    }
};