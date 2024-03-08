#include <unordered_map>
#include <iostream>

using namespace std;

bool generateDocument(string characters, string document) {
    // Time: O(n + m), Space: O(c)
    unordered_map<char, int> characters_ft, document_ft;
    for (char letter: characters)
        characters_ft[letter]++;

    for (char letter: document)
        document_ft[letter]++;

    for (const auto &[letter, count]: document_ft)
        if (characters_ft.find(letter) == characters_ft.end() || characters_ft[letter] < count)
            return false;

    return true;
}
