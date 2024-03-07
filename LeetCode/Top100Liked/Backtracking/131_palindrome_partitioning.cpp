#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<int>> result;
        vector<int> combination;
        vector<vector<string>> palindromes;

        generate(0, combination, result, s.size());

        for (auto str_set: result) {
            bool is_palindrome = true; // true if all substrings in a set are palindrome
            int start = 0;
            vector<string> current_palindromes;

            for (auto end: str_set) {
                is_palindrome &= isPalindrome(start, end, s);
                current_palindromes.push_back(s.substr(start, end - start + 1));
                start = end + 1;
            }

            if (is_palindrome)
                palindromes.push_back(current_palindromes);
        }

        return palindromes;
    }


    void generate(int end, vector<int> &curr_combination, vector<vector<int>> &result, int n) {
        if (end == n) {
            result.push_back(curr_combination);
            return;
        }

        for (int i = end; i < n; i++) {
            curr_combination.push_back(i);
            generate(i + 1, curr_combination, result, n);
            curr_combination.pop_back();
        }
    }

    bool isPalindrome(int start, int end, const string &str) {
        bool result = true;
        int fp = start, sp = end;
        while (start < end)
            result &= str[start++] == str[end--];
        return result;
    }

    /**
    n = 4
    1
        2
            3
                4
            4
        3
            4
        4
    2
        3
            4
        4
    3
        4
    4
    */

};