class Solution {
public:
    bool checkPerfectNumber(int num) {
        // Time: O(n), Space: O(1)
        unordered_set<int> divisors;
        int sum = 0;
        for(int i = 1; i <= num / 2; i++)
            if(num % i == 0)
                divisors.insert(i);

        for(auto each: divisors)
            sum += each;
        return sum == num;
    }
};