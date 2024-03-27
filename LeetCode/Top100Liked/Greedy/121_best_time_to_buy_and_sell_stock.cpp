class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Time: O(n), Space: O(1)
        int first = INT_MAX;
        int answer = 0;
        for (int i = 0; i < prices.size(); i++) {
            first = std::min(prices[i], first);
            answer = std::max(answer, prices[i] - first);
        }

        return answer;
    }
};