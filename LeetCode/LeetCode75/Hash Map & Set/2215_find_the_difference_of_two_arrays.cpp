class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // Time: O(n), Space: O(n)
        unordered_set<int> first(nums1.begin(), nums1.end()), second(nums2.begin(), nums2.end());
        vector<int> in_first, in_second;
        for(auto num: first)
            if(second.find(num) == second.end())
                in_first.push_back(num);

        for(auto num: second)
            if(first.find(num) == first.end())
                in_second.push_back(num);

        return {in_first, in_second};
    }
};