class Solution {
public:
    vector<int> countBits(int n) {
        // Time: O(n), Space: O(n)
        vector<int> result;
        for(int i = 0; i <= n; i++)
            result.push_back(bits_count(i));

        return result;
    }

    int bits_count(int n){
        int cnt = 0;
        while(n){
            cnt += n & 1;
            n >>= 1;
        }

        return cnt;
    }
};