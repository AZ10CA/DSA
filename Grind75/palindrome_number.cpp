class Solution {
public:
    bool isPalindrome(int x) {
        // Time: O(logn), Space: O(1)
        if(x < 0)
            return false;

        auto size = digits_count(x);
        if(size <= 1)
            return true;

        while(size > 1){
            int last = extract_last(x);
            size--;
            int first = extract_first(x, size);
            size--;

            cout << first << ", " << last << endl;

            if(first != last)
                return false;
        }

        return true;
    }

    int digits_count(int x){
        int cnt = 0;

        while(x){
            cnt++;
            x /= 10;
        }

        return cnt;
    }

    int extract_last(int& x){
        auto last_digit = x % 10;
        x /= 10;
        return last_digit;
    }

    int extract_first(int& x, int size){
        if(not x)
            return 0;

        int power = std::pow(10, size - 1);
        auto first_digit = x / power;
        x %= power;

        return first_digit;
    }

    bool string_solution(int x){
        // Time: O(logn), Space: O(logn)
        auto str = to_string(x);
        int left = 0, right = str.size() - 1;
        while(left <= right){
            if(str[left] != str[right])
                return false;

            left++, right--;
        }

        return true;
    }
};