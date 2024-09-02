class Solution {
public:
    vector<int> countBits(int n) {
        // Time: O(n), Space: O(n)
        vector<int> result(n + 1, 0);
        for(int i = 0; i < result.size(); i++)
            result[i] = count_bits(i);

        return result;
    }

    int count_bits(int n){
        int cnt = 0;

        while(n){
            n = n & (n - 1);
            cnt++;
            n >>= 1;
        }

        return cnt;
    }
};