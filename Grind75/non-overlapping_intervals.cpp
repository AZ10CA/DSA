class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Time: O(nlogn), Space: O(1)
        std::sort(intervals.begin(), intervals.end(), [](auto& first, auto& second){
            if(first[1] == second[1])
                return first[0] > second[0];
            return first[1] < second[1];
        });

        int cnt = 0;
        int last_interval_idx = 0;

        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < intervals[last_interval_idx][1])
                cnt++;
            else
                last_interval_idx = i;
        }

        return cnt;
    }
};