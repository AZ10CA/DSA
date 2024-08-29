class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        // Time: O(nm), Space: O(1)
        vector<unordered_set<char>> rows = {
            {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'},
            {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'},
            {'z', 'x', 'c', 'v', 'b', 'n', 'm'}
        };

        vector<string> result;

        for (auto& word : words) {
            string lower_word = toLower(word);
            for (auto& row : rows) {
                if (can_type(row, lower_word)) {
                    result.push_back(word);
                    break;
                }
            }
        }

        return result;
    }

private:
    bool can_type(const unordered_set<char>& row, const string& word) {
        for (char letter : word)
            if (row.find(letter) == row.end())
                return false;

        return true;
    }

    string toLower(const string& str) {
        string lower_str = str;
        for (char& c : lower_str) {
            c = tolower(c);
        }
        return lower_str;
    }
};
