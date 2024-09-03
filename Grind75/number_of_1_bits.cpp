class Solution {
public:
    int hammingWeight(int n) {
        // Time: O(logn), Space: O(1)
        int cnt = 0;
        while(n){
            cnt++;
            n = n & (n - 1);
        }

        return cnt;
    }
};