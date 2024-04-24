class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        // Time: O(n), Space: O(n)
        if(nums.empty())
            return {};

        int start = nums[0];
        vector<string> result;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] - 1 == nums[i - 1]){
                // continue the streak
                continue;
            } else {
                // start a new streak
                auto end = nums[i - 1];
                result.push_back(get_range(start, end));
                start = nums[i];
            }
        }
        result.push_back(get_range(start, nums[nums.size() - 1]));

        return result;
    }

    string get_range(int start, int end){
        assert(start <= end);
        if(start == end)
            return to_string(start);

        return to_string(start) + "->" + to_string(end);
    }
};