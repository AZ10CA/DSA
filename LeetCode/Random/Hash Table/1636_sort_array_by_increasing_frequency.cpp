class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        // Time: O(nlogn), Space: O(n)
        unordered_map<int, int> ft;
        for(auto num: nums)
            ft[num]++;

        std::sort(nums.begin(), nums.end(), [&](auto& first, auto& second){
            if(ft[first] == ft[second])
                return first > second;
            return ft[first] < ft[second];
        });

        return nums;
    }
};