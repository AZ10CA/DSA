class Solution {
#define ull unsigned long long
public:
    int mySqrt(int x) {
        // Time: O(logn), Space: O(1)
        if(x <= 1)
            return x;
        ull min = 1, max = x / 2;
        ull answer = 0;
        while(min <= max){
            ull middle = min + (max - min) / 2;
            ull result = middle * middle;
            if(result == x)
                return middle;
            if(result < x){
                answer = middle;
                min = middle + 1;
            } else max = middle - 1;
        }

        return answer;
    }
};