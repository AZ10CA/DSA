class Solution {

public:
    double myPow(double x, long long n) {
        // Time: O(logn), Space: O(logn)
        if(n < 0)
            return 1.0 / myPow(x, -n);

        if(n == 0)
            return 1;

        if(n == 1)
            return x;

        if(n & 1)
            return x * myPow(x, n - 1);

        auto result = myPow(x, n / 2);
        return result * result;
    }
};