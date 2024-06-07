class Solution {
public:
    int hammingDistance(int x, int y) {
        // Time: O(1), Space: O(1)
        int result = x xor y;
        int cnt = 0;

        while(result){
            auto last_bit = result & 1;
            cnt += last_bit;
            result >>= 1;
        }

        return cnt;
    }
};