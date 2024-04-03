class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<char>> result;
        vector<char> combination;
        generate_combinations(0, combination, result, n * 2);
        auto valid_combinations = filter_combinations(result);

        return valid_combinations;

    }

    void generate_combinations(int idx, vector<char> &combination, vector<vector<char>> &result, int n) {
        if (idx == n && combination.size()) {
            result.push_back(combination);
            return;
        }

        vector<char> options = {'(', ')'};
        for (auto letter: options) {
            combination.push_back(letter);
            generate_combinations(idx + 1, combination, result, n);
            combination.pop_back();
        }
    }


    bool isValid(const vector<char> &combination) {
        stack<char> st;
        for (auto letter: combination) {
            if (letter == '(')
                st.push(letter);
            else {
                if (st.empty() || st.top() != '(')
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }

    string to_string(const vector<char> &str) {
        string result;
        for (auto letter: str)
            result.push_back(letter);
        return result;
    }

    vector<string> filter_combinations(const vector<vector<char>> &combinations) {
        vector<string> result;
        for (const auto &comb: combinations) {
            if (isValid(comb))
                result.push_back(to_string(comb));
        }

        return result;
    }
};
