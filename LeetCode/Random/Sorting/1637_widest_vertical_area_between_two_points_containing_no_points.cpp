class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        // Time: O(nlogn), Space: O(1)
        std::sort(points.begin(), points.end(), [](auto& first, auto& second){
            return first[0] < second[0];
        });

        int answer = 0;
        for(int i = 1; i < points.size(); i++)
            answer = std::max(answer, points[i][0] - points[i - 1][0]);

        return answer;
    }
};