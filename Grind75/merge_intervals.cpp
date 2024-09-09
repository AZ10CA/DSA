class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Time: O(nlogn), Space: O(n)
        int idx = 0;
        vector<vector<int>> result;
        vector<int> current_interval;


        // sort the intervals based on their starting point
        std::sort(intervals.begin(), intervals.end(), [](vector<int> first, vector<int> second){
            if(first[0] == second[0])
                return first[1] < second[1];

            return first[0] < second[0];
        });

        current_interval = intervals[0];

        // merge the intervals
        while(idx < intervals.size()){
            if(is_overlapping(current_interval, intervals[idx])){
                current_interval = merge(current_interval, intervals[idx]);
                idx++;
                continue;
            }

            result.push_back(current_interval);
            current_interval = intervals[idx];
            idx++;
        }

        result.push_back(current_interval);
        return result;
    }

    bool is_overlapping(const vector<int>& first, const vector<int>& second){
        return first[0] >= second[0] && first[0] <= second[1] || second[0] >= first[0] && second[0] <= first[1];
    }

    vector<int> merge(const vector<int>& first, const vector<int>& second){
        return {std::min(first[0], second[0]), std::max(first[1], second[1])};
    }
};