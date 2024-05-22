#include <iostream>

using namespace std;

bool isPalindrome(string str) {
    // Time: O(n), Space: O(1)
    int fp = 0, sp = str.size() - 1;

    while (fp < sp)
        if (str[fp++] != str[sp--])
            return false;

    return true;
}
