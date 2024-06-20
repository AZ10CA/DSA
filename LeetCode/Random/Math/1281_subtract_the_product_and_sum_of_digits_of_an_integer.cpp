class Solution {
public:
    int subtractProductAndSum(int n) {
        // Time: O(logn), Space: O(logn)
        auto digits = to_string(n);
        int sum = 0, mul = 1;

        for(auto ch: digits){
            sum += ch - '0';
            mul *= ch - '0';
        }

        return mul - sum;
    }

};