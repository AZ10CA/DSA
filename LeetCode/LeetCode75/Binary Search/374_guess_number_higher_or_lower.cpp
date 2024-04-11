/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        // Time: O(logn), Space: O(1)
        int min = 1;
        int max = n;
        while(min <= max){
            auto my_guess = min + (max - min) / 2;
            auto result = guess(my_guess);
            if(result == 0)
                return my_guess;

            if(result == 1)
                min = my_guess + 1;
            else
                max = my_guess - 1;
        }

        return 0;
    }
};