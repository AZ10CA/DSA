class Solution {
    // Time & Space: O(4^n * n)
    unordered_map<char, vector<char>> mapping = {
            {'1', {}},
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}},
            {'0', {}}
    };

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        vector<char> combination;

        generate(0, combination, result, digits);

        return result;
    }

    string to_string(const vector<char> &vec) {
        string result;
        for (auto letter: vec)
            result.push_back(letter);
        return result;
    }

    void generate(int idx, vector<char> &combination, vector<string> &result, const string &digits) {
        if (idx == digits.size() && combination.size() == digits.size() && combination.size()) {
            result.push_back(to_string(combination));
            return;
        }

        for (auto letter: mapping[digits[idx]]) {
            combination.push_back(letter);
            generate(idx + 1, combination, result, digits);
            combination.pop_back();
        }
    }
};