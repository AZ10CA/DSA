class Solution {
public:
    int maxCoins(vector<int>& piles) {
        // Time: O(nlogn), Space: O(1)
        auto sum = 0;
        std::sort(piles.begin(), piles.end());
        int iterations = piles.size() / 3;
        int idx = piles.size() - 2;

        while(iterations--){
            sum += piles[idx];
            idx -= 2;
        }

        return sum;
    }
};