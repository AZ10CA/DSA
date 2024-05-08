class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // Time: O(n + m), Space: O(1)
        int curr_i = 0, curr_j = grid[0].size() - 1;
        int cnt = 0;

        while(curr_i >= 0 && curr_j >= 0 && curr_i < grid.size() && curr_j < grid[0].size()){
            auto num = grid[curr_i][curr_j];
            if(num >= 0)
                curr_i += 1;
            else {
                cnt += grid.size() - curr_i;
                curr_j--;
            }
        }

        return cnt;
    }
};