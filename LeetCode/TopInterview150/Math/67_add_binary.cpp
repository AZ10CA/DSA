class Solution {
public:
    string addBinary(string a, string b) {
        // Time: O(n), Space: O(n)
        int a_idx = a.size() - 1;
        int b_idx = b.size() - 1;
        bool has_carry = false;
        string result;

        while(a_idx >= 0 || b_idx >= 0){
            int first = a_idx >= 0 ? a[a_idx--] - '0': 0;
            int second = b_idx >= 0 ? b[b_idx--] - '0' : 0;

            int sum = first + second + has_carry;
            has_carry = false;
            has_carry = sum > 1;
            sum %= 2;
            result.push_back(sum + '0');
        }

        if(has_carry)
            result.push_back('1');

        std::reverse(result.begin(), result.end());

        return result;
    }
};