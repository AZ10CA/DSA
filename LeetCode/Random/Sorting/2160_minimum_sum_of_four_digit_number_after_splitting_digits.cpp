class Solution {
public:
    int minimumSum(int num) {
        // Time: O(1), Space: O(1)
        vector<int> digits;
        while(num){
            auto last_digit = num % 10;
            num /= 10;
            digits.push_back(last_digit);
        }

        std::sort(digits.begin(), digits.end());

        return digits[0] * 10 + digits[3] + digits[1] * 10 + digits[2];
    }
};