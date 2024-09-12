class Solution {
    unordered_map<int, string> mapping = {
            {1, ""},
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
    };

public:
    vector<string> letterCombinations(string digits) {
        // Time: O(4^n), Space: O(4^n)
        if(digits.empty())
            return {};

        string combination;
        vector<string> result;

        generate(0, combination, result, digits);

        return result;
    }

    void generate(int idx, string& combination, vector<string>& result, const string& digits){
        if(idx == digits.size()){
            result.push_back(combination);
            return;
        }

        const string& letters = mapping[digits[idx] - '0'];
        for(auto letter: letters){
            combination.push_back(letter);
            generate(idx + 1, combination, result, digits);
            combination.pop_back();
        }
    }
};