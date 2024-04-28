class Solution {
public:
    bool isPalindrome(int x) {
        // Time: O(1), Space: O(1)
        int len = length_of(x);
        if(x < 0)
            return false;

        while(x && len > 1){
            int first_digit = (x / (int)std::pow(10, len - 1)) % 10;
            int last_digit = x % 10;
            if(first_digit != last_digit)
                return false;

            len -= 2;
            x /= 10;
        }

        return true;
    }

    int length_of(int x){
        x = std::abs(x);
        int size = 1;
        while(x >= 10){
            x /= 10;
            size++;
        }

        return size;
    }
};