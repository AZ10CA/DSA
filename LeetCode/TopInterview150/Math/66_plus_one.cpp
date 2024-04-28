class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // Time: O(n), Space: O(1)
        vector<int> result;

        int idx = digits.size() - 1;
        while(idx >= 0){
            auto& digit = digits[idx];
            if(digit == 9){
                digit = 0;
                idx--;
                continue;
            }
            digit += 1;
            return digits;
        }

        std::reverse(digits.begin(), digits.end());
        digits.push_back(1);
        std::reverse(digits.begin(), digits.end());

        return digits;
    }
};