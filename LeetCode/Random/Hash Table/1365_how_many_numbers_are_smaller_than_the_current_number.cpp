class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // Time: O(nlogn), Space: O(n)
        vector<int> original = nums;
        vector<int> result;

        std::sort(nums.begin(), nums.end());
        auto& sorted = nums;

        for(auto num: original){
            int cnt = std::distance(sorted.begin(), std::lower_bound(sorted.begin(), sorted.end(), num));
            result.push_back(cnt);
        }

        return result;
    }
};