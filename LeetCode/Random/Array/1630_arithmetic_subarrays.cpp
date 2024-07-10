class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        // Time: O(mn), Space: O(n);
        vector<bool> answers;
        for(int i = 0; i < l.size(); i++){
            int start = l[i], end = r[i];

            if(end - start + 1 < 2){
                answers.push_back(false);
                continue;
            }

            answers.push_back(solve(nums, start, end));
        }

        return answers;
    }

    bool solve(const vector<int>& nums, int start, int end){
        unordered_set<int> range_nums;
        int mn = INT_MAX, mx = INT_MIN;

        for(int i = start; i <= end; i++){
            mn = std::min(mn, nums[i]);
            mx = std::max(mx, nums[i]);
            range_nums.insert(nums[i]);
        }

        int step = (mx - mn) / (end - start);
        if((mx - mn) % (end - start) != 0)
            return false;

        for(int i = mn; i < mx; i += step)
            if(range_nums.find(i) == range_nums.end())
                return false;

        return true;
    }
};