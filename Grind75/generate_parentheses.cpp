class Solution {
    string current;
    vector<string> result;
public:
    vector<string> generateParenthesis(int n) {
        generate(0, 0, n);

        return result;
    }

    void generate(int opening_count, int closing_count, int n){
        // Time: O(2^n), Space: O(2^n)
        if(closing_count > opening_count || opening_count > n || closing_count > n)
            return;

        if(opening_count == n && closing_count == n){
            result.push_back(current);
            return;
        }

        // use opening
        current.push_back('(');
        generate(opening_count + 1, closing_count, n);
        current.pop_back();

        // use closing
        current.push_back(')');
        generate(opening_count, closing_count + 1, n);
        current.pop_back();
    }
};