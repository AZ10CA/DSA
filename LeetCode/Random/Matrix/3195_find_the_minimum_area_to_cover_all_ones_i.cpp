class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        // Time: O(n^2), Space: O(n^2)
        vector<int> rows, cols;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[i].size(); j++)
                if(grid[i][j] == 1){
                    rows.push_back(i);
                    cols.push_back(j);
                }

        std::sort(rows.begin(), rows.end());
        std::sort(cols.begin(), cols.end());


        int top_row = rows[0], bottom_row = rows[rows.size() - 1];
        int left_col = cols[0], right_col = cols[cols.size() - 1];

        return (bottom_row - top_row + 1) * (right_col - left_col + 1);
    }
};