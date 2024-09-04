class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        return integer_solution(n);
    }

    uint32_t bitset_solution(uint32_t n){
        // Time: O(logn), Space: O(1)
        bitset<32> result;
        int idx = 0;
        while(n){
            auto last_bit = n & 1;
            n >>= 1;
            result[32 - idx - 1] = last_bit;
            idx++;
        }

        return result.to_ulong();
    }

    uint32_t integer_solution(uint32_t n){
        uint32_t result = 0;

        for(int i = 0; i < 32; i++){
            bool last = n & 1;
            n >>= 1;

            int reversed = last << (32 - i - 1);
            result |= reversed;
        }

        return result;
    }
};