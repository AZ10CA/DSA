class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // Time: O(n), Space: O(n)
        unordered_map<int, int> ft; // frequency table
        for(auto num: nums)
            ft[num]++;

        auto cnt = 0;
        for(auto&[num, frequency]: ft)
            cnt += sum_up_to(frequency - 1);

        return cnt;

    }

    int sum_up_to(int n){
        return n * (n + 1) / 2;
    }
};