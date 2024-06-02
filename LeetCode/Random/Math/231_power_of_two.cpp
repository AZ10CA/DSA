class Solution {
public:
    bool isPowerOfTwo(int n) {
        // Time: O(1), Space: O(1)
        if(n <= 0)
            return false;
        return (n & (n - 1)) == 0;
    }
};