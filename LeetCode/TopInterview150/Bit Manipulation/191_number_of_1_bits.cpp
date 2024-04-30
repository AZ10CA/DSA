class Solution {
public:
    int hammingWeight(int n) {
        // Time: O(1), Space: O(1)
        auto cnt = 0;

        while(n){
            auto last_bit = n & 1;
            n >>= 1;
            cnt += last_bit;
        }

        return cnt;
    }
};