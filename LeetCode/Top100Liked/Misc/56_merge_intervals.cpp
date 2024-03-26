class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Time: O(nlogn), Space: O(n)
        std::sort(intervals.begin(), intervals.end(), [](const auto& first, const auto& second){
            return first[0] < second[0];
        });

        vector<vector<int>> result;
        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){
            auto current = intervals[i];
            if(end >= current[0])
                end = std::max(end, current[1]);
            else {
                result.push_back({start, end});
                start = current[0];
                end = current[1];
            }
        }

        result.push_back({start, end});
        return result;
    }
};