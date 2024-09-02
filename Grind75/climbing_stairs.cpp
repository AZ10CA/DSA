class Solution {
    vector<int> table;
public:
    int climbStairs(int n) {
        // table = vector<int>(n + 1, -1);
        // return recursive_dp(0, n);
        return iterative(n);
    }

    int iterative(int n){
        // Time: O(n), Space: O(1)
        if(n <= 2)
            return n;

        int stairs[2] = {1, 2};
        int answer = 0;
        for(int i = 3; i <= n; i++){
            answer = stairs[0] + stairs[1];
            stairs[0] = stairs[1];
            stairs[1] = answer;
        }

        return answer;
    }

    int recursive_dp(int current, int n){
        // Time: O(n), Space: O(n)
        if(current == n)
            return 1;

        if(current > n)
            return 0;

        auto& memo = table[current];
        if(memo != -1)
            return memo;

        return memo = recursive_dp(current + 1, n) + recursive_dp(current + 2, n);
    }
};