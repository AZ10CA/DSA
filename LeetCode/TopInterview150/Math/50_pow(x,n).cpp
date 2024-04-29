class Solution {
public:
    double myPow(double x, int n) {
        // Time: O(logn), Space: O(logn)
        if(n == 0)
            return 1;
        double num = n < 0 ? ((double)1 / x) : x;
        n = std::abs(n);
        double result = 1;

        auto half = myPow(num, n / 2);
        if(n % 2 == 0)
            return half * half;
        else return half * half * num;

        return result;
    }
};