class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Time: O(n), Space: O(1)
        int buy_value = INT_MAX;
        int answer = 0;

        for(auto price: prices){
            if(price < buy_value)
                buy_value = price;
            else
                answer = std::max(answer, price - buy_value);
        }

        return answer;
    }
};