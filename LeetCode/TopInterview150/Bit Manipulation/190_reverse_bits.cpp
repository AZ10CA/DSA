class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // Time: O(1), Space: O(1)
        int result = 0;
        for(int i = 0; i < 32; i++){
            int right_most = (n & 1); // extract the last bit
            n >>= 1; // pop the last bit

            int reversed = right_most << (31 - i);
            result |= reversed;
        }

        return result;
    }
};