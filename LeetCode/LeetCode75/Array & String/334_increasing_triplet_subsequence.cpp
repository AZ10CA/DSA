class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // Time: O(n), Space: O(1)
        int first = INT_MAX, second = INT_MAX;
        for(auto num: nums)
            if(num <= first)
                first = num;
            else if(num <= second)
                second = num;
            else
                return true;

        return false;
    }
};