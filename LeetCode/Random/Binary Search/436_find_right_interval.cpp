struct Interval {
    int start;
    int end;
    int idx;

    Interval(int start, int end, int idx): start(start), end(end), idx(idx){}
};

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& _intervals) {
        // Time: O(nlogn), Space: O(n)
        vector<int> result(_intervals.size());
        vector<Interval> intervals;

        int idx = 0;
        for(auto& in: _intervals)
            intervals.push_back(Interval(in[0], in[1], idx++));

        std::sort(intervals.begin(), intervals.end(), [](auto& first, auto& second){
            return first.start < second.start;
        });

        for(int i = 0; i < intervals.size(); i++){
            int end = intervals[i].end;
            int left = 0, right = intervals.size() - 1;
            int closest_idx = -1;

            while(left <= right){
                int middle = left + (right - left) / 2;
                if(intervals[middle].start >= end){
                    closest_idx = middle;
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
            }
            result[intervals[i].idx] = closest_idx == -1 ? -1 : intervals[closest_idx].idx;
        }

        return result;
    }
};