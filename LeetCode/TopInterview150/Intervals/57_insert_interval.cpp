class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Time: O(n), Space: O(n)
        vector<vector<int>> result;
        int idx = 0;

        // add all intervals that end before the start of the newInterval (non-overlapping)
        while(idx < intervals.size() && intervals[idx][1] < newInterval[0])
            result.push_back(intervals[idx++]);

        // add all intervals that merge with newInterval
        while(idx < intervals.size() && intervals[idx][0] <= newInterval[1]){
            auto new_start = std::min(newInterval[0], intervals[idx][0]);
            auto new_end = std::max(newInterval[1], intervals[idx][1]);
            idx++;
            newInterval = {new_start, new_end};
        }

        result.push_back(newInterval);

        // add the rest of the intervals
        while(idx < intervals.size())
            result.push_back(intervals[idx++]);

        return result;
    }
};