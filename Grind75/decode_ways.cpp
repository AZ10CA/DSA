class Solution {
    vector<int> table;
public:
    int numDecodings(string s) {
        // Time: O(n), Space: O(n)
        table = vector<int>(s.size(), -1);
        return traverse(0, s);
    }

    int traverse(int idx, const string& str){
        if(idx > str.size() || str[idx] == '0')
            return 0;

        if(idx == str.size())
            return 1;
        auto& memo = table[idx];
        if(memo != -1)
            return memo;

        auto take_one = traverse(idx + 1, str);
        auto take_two = 0;
        auto two_digits = stoi(str.substr(idx, 2));
        if(two_digits <= 26 && two_digits > 9)
            take_two = traverse(idx + 2, str);

        return memo = take_one + take_two;
    }
};