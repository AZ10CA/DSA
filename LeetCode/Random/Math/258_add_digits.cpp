class Solution {
public:
    int addDigits(int num) {
        if(num < 10)
            return num;
        return addDigits(sum_digits(num));
    }

    int sum_digits(int num){
        auto sum = 0;
        while(num){
            auto last_digit = num % 10;
            num /= 10;
            sum += last_digit;
            cout << num << endl;
        }

        return sum;
    }
};