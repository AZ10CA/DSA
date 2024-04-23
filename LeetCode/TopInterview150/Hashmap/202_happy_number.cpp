class Solution {
public:
    bool isHappy(int n) {
        // Time: O(logn), Space: O(logn)
        unordered_set<int> seen;

        while(n != 1){
            auto sum = sum_of_squared_digits(n);
            if(seen.find(sum) != seen.end())
                return false;
            seen.insert(sum);
            n = sum;
        }

        return true;
    }

    int sum_of_squared_digits(int n){
        int sum = 0;

        while(n != 0){
            auto last_digit = n % 10;
            sum += last_digit * last_digit;
            n /= 10;
        }

        return sum;
    }
};