class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        // Time: O(1), Space: O(1)
        if(num % 3 != 0)
            return {};

        auto divided = num / 3;
        return {divided - 1, divided, divided + 1};
    }
};