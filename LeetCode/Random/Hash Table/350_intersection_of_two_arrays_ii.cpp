class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // Time: O(n + m), Space: O(n + m)
        unordered_map<int, int> ft1, ft2;
        vector<int> result;

        for(auto each: nums1)
            ft1[each]++;

        for(auto each: nums2)
            ft2[each]++;

        for(auto&[num, cnt]: ft1)
            if(ft2.find(num) == ft2.end())
                continue;
            else for(int i = 0; i < std::min(cnt, ft2[num]); i++)
                    result.push_back(num);


        return result;
    }
};