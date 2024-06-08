class Solution {
public:
    int arrangeCoins(int n) {
        // Time: O(n), Space: O(1)
        long long sum = 0;
        long long increment = 0;
        while(sum < n)
            sum += increment++;

        return increment - 1 - (sum > n);
    }

};