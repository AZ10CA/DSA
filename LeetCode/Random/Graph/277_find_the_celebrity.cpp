/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        // Time: O(n), Space: O(1), 3n - 1 calls made which is less than the 3n API limit
        int celebrity = 0;
        for(int i = 1; i < n; i++){
            if(knows(celebrity, i))
                celebrity = i;
        }

        // make sure everyone knows this celebrity
        for(int i = 0; i < n; i++)
            if(i != celebrity && not knows(i, celebrity))
                return -1;

        // and the celebrity doesn't know anyone
        for(int i = 0; i < n; i++)
            if(knows(celebrity, i) && i != celebrity)
                return -1;

        return celebrity;
    }
};