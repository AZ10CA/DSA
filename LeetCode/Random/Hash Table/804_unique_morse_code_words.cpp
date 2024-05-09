class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        // Time: O(n), Space: O(n)
        unordered_set<string> unique_transformations;

        for(auto& word: words)
            unique_transformations.insert(transformation(word));

        return unique_transformations.size();

    }

    string transformation(const string& word){
        string result;
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        for(auto ch: word)
            result += morse[ch - 'a'];

        return result;
    }
};