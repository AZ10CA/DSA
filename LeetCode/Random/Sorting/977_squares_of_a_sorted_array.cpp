class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // Time: O(n), Space: O(n)
        vector<int> pos, neg;
        for(auto num: nums){
            auto& arr = num < 0 ? neg : pos;
            arr.push_back(num * num);a
        }

        std::reverse(neg.begin(), neg.end());

        return merge_sorted_arrays(neg, pos);
    }


    vector<int> merge_sorted_arrays(const vector<int>& first, const vector<int>& second){
        vector<int> result(first.size() + second.size());
        int fi = 0, si = 0;
        int idx = 0;
        while(fi < first.size() && si < second.size())
            if(first[fi] < second[si])
                result[idx++] = first[fi++];
            else result[idx++] = second[si++];

        while(fi < first.size())
            result[idx++] = first[fi++];

        while(si < second.size())
            result[idx++] = second[si++];

        return result;
    }
};