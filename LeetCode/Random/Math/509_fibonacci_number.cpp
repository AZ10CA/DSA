class Solution {
public:
    int fib(int n) {
        if(n <= 1)
            return n;
        int first = 0, second = 1;
        for(int i = 2; i <= n; i++){
            int temp = second;
            second = second + first;
            first = temp;
        }

        return second;
    }
};
