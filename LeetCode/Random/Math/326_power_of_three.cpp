class Solution {
public:
    bool isPowerOfThree(int n) {
        // Time: O(logn), Space: O(1)
        if(n == 0)
            return false;

        while(n > 1 && n % 3 == 0)
            n /= 3;

        return n == 1;
    }
};