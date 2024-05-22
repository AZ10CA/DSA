#include <iostream>

using namespace std;

string get_encoding(int count, char ch);

string runLengthEncoding(string str) {
    // Time: O(n), Space: O(1)
    if (str.empty())
        return "";
    string result;

    int curr_char_count = 0;
    char curr_char = str[0];
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == curr_char)
            curr_char_count++;
        else {
            result += get_encoding(curr_char_count, curr_char);
            curr_char = str[i];
            curr_char_count = 1;
        }
    }
    result += get_encoding(curr_char_count, curr_char);

    return result;
}

string get_encoding(int count, char ch) {
    string result;
    int cnt = count / 9;
    int remaining = count % 9;
    while (cnt--) {
        result += "9";
        result += ch;
    }
    if (remaining != 0) {
        result += to_string(remaining);
        result += ch;
    }
    return result;
}
