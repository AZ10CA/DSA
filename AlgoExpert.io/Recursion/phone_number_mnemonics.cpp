#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

unordered_map<char, vector<char>> letters = {
// Time & Space: O(4^n * n)
        {'1', {'1'}},
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}},
        {'0', {'0'}}
};

void create_combinations(const string &word, int idx, string &current_combination, vector<string> &result) {
    if (current_combination.size() == word.size()) {
        result.push_back(current_combination);
        return;
    }
    for (auto letter: letters[word[idx]]) {
        current_combination.push_back(letter);
        create_combinations(word, idx + 1, current_combination, result);
        current_combination.pop_back();
    }

}

vector<string> phoneNumberMnemonics(string phoneNumber) {
    vector<string> combinations;
    string combination = "";

    create_combinations(phoneNumber, 0, combination, combinations);

    return combinations;
}

