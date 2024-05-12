class Solution {
public:
    int findMaxK(vector<int>& nums) {
        // Time: O(n), Space: O(n)
        unordered_set<int> nums_set(nums.begin(), nums.end());
        int answer = -1;
        for(auto num: nums)
            if(nums_set.find(-num) != nums_set.end())
                answer = std::max(std::abs(num), answer);

        return answer;
    }
};