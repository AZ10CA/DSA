class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Time: O(n), Space: O(1)
        unordered_set<int> nums_set(nums.begin(), nums.end());
        int answer = 0;

        for(auto num: nums){
            auto is_start = nums_set.find(num - 1) == nums_set.end();
            if(not is_start)
                continue;

            int cnt = 1;
            while(nums_set.find(++num) != nums_set.end())
                cnt++;

            answer = std::max(cnt, answer);
        }

        return answer;
    }
};