class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // Time: O(nlogn), Space: O(1)
        std::sort(points.begin(), points.end(), [](const auto& first, const auto& second){
            return first[1] < second[1];
        });

        auto cnt = 0;
        auto current_end = points[0][1];
        for(int i = 1; i < points.size(); i++){
            if(current_end >= points[i][0])
                continue;
            else {
                cnt++;
                current_end = points[i][1];
            }
        }

        cnt++;
        return cnt;
    }
};
