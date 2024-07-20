class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        // Time: O(n + m), Space: O(n + m)
        unordered_set<int> f, s;
        for(auto each: nums1)
            f.insert(each);

        for(auto each: nums2)
            s.insert(each);

        int f_cnt = 0, s_cnt = 0;
        for(auto each: nums1)
            if(s.find(each) != s.end())
                f_cnt++;

        for(auto each: nums2)
            if(f.find(each) != f.end())
                s_cnt++;


        return {f_cnt, s_cnt};
    }
};