class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // Time: O(n), Space: O(n)
        vector<int> negatives, positives;

        for(auto num: nums){
            auto& which = num < 0 ? negatives : positives;
            which.push_back(num * num);
        }

        std::reverse(negatives.begin(), negatives.end());

        return merge_two_sorted_arrays(negatives, positives);
    }

    vector<int> merge_two_sorted_arrays(const vector<int>& first, const vector<int>& second){
        vector<int> result;
        int f_idx = 0, s_idx = 0;

        while(f_idx < first.size() && s_idx < second.size()){
            auto f_num = first[f_idx], s_num = second[s_idx];

            if(f_num < s_num){
                result.push_back(f_num);
                f_idx++;
            } else {
                result.push_back(s_num);
                s_idx++;
            }
        }

        while(f_idx < first.size())
            result.push_back(first[f_idx++]);

        while(s_idx < second.size())
            result.push_back(second[s_idx++]);

        return result;
    }
};