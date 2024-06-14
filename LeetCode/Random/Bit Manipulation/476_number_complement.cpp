class Solution {
public:
    int findComplement(int num) {
        // Time: O(log n), Space: O(1)
        int ans = 0;
        int position = 0;
        while(num){
            int last_bit = num & 1;
            ans |= not last_bit * (1 << position);
            position++;
            num >>= 1;
        }

        return ans;
    }
};