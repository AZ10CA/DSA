class Solution {
public:
    bool isUgly(int n) {
        // Time: O(log n), Space: O(log n)
        if(n < 1)
            return false;

        if(n == 1)
            return true;

        vector<int> factors = {2, 3, 5};
        for(auto factor: factors)
            if(n % factor == 0)
                return isUgly(n / factor);

        return false;
    }
};