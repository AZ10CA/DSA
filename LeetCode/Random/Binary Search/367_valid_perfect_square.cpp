class Solution {
public:
    bool isPerfectSquare(int num) {
        // Time: O(logn), Space: O(1)
        int left = 1, right = num;
        while(left <= right){
            int middle = left + (right - left) / 2;
            if(num % middle == 0 && num / middle == middle)
                return true;
            if(middle < num / middle)
                left = middle + 1;
            else
                right = middle - 1;
        }

        return false;
    }
};