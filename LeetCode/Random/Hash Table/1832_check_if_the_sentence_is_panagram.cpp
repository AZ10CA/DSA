class Solution {
public:
    bool checkIfPangram(string sentence) {
        // Time: O(n), Space: O(1)

        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        unordered_set<char> alpha(alphabet.begin(), alphabet.end());
        unordered_set<char> characters(sentence.begin(), sentence.end());

        return alpha == characters;
    }
};