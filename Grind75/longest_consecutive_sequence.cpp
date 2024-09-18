class Solution {
public:
    int longestConsecutive(vector<int>& _nums) {
        // Time: O(n), Space: O(1)
        int answer = 0;
        unordered_set<int> nums(_nums.begin(), _nums.end());

        for(auto& n: _nums){
            if(nums.find(n - 1) != nums.end())
                continue;

            int left = n, right = n;

            while(nums.find(right + 1) != nums.end())
                right++;

            int length = right - left + 1;
            answer = std::max(length, answer);
        }


        return answer;
    }
};