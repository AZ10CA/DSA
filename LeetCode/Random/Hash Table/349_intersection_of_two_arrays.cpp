class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Time: O(m + n), Space: O(k), k: intersection size
        bitset<1001> first, second;
        for(auto num: nums1)
            first[num] = true;

        for(auto num: nums2)
            second[num] = true;

        vector<int> result;
        auto intersection = first & second;
        for(int i = 0; i < intersection.size(); i++)
            if(intersection[i])
                result.push_back(i);


        return result;
    }
};