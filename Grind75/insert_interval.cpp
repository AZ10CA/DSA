class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // Time: O(n), Space: O(n)
        vector<vector<int>> result;
        int idx = 0;

        while(idx < intervals.size() && intervals[idx][1] < newInterval[0])
            result.push_back(intervals[idx++]);

        while(idx < intervals.size() && is_overlapping(intervals[idx], newInterval)){
            newInterval = merge(intervals[idx], newInterval);
            idx++;
        }

        result.push_back(newInterval);

        while(idx < intervals.size())
            result.push_back(intervals[idx++]);

        return result;
    }

    bool is_overlapping(const vector<int>& first, const vector<int>& second){
        return first[0] >= second[0] && first[0] <= second[1] || second[0] >= first[0] && second[0] <= first[1];
    }

    vector<int> merge(const vector<int>& first, const vector<int>& second){
        return {std::min(first[0], second[0]), std::max(first[1], second[1])};
    }
};