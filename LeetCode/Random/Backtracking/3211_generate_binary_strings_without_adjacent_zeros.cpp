class Solution {
public:
    vector<string> validStrings(int n) {
        // Time: O(2^n), Space: O(2^n)
        vector<string> substrings;
        string current;

        generate(current, substrings, n);

        return substrings;
    }

    void generate(string current, vector<string>& result, const int size){
        if(current.size() == size){
            result.push_back(current);
            return;
        }

        char last = current.empty() ? '1' : current[current.size() - 1];
        if(last == '1'){
            current.push_back('1');
            generate(current, result, size);
            current.pop_back();
            current.push_back('0');
            generate(current, result, size);
        } else {
            current.push_back('1');
            generate(current, result, size);
        }
    }
};