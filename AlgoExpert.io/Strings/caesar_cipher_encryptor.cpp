#include <iostream>

using namespace std;

string caesarCypherEncryptor(string str, int key) {
    // Time: O(n), Space: O(1)
    for (auto &letter: str)
        letter = (letter + key - 'a') % 26 + 'a';

    return str;
}
