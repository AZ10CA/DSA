class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        // Time: O(n), Space: O(1)
        int sum = 0;
        for(auto num: nums)
            sum += num - digit_sum(num);

        return std::abs(sum);
    }

    int digit_sum(int n){
        auto sum = 0;
        while(n){
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }
};