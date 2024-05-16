class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        // Time: O(n^2), Space: O(n^2)
        vector<int> max_rows, max_cols;
        auto sum = 0;
        int size = grid.size();

        for(auto row: grid){
            int max = 0;
            for(int i = 0; i < row.size(); i++)
                max = std::max(max, row[i]);
            max_rows.push_back(max);
        }

        for(int i = 0; i < size; i++){
            int max = 0;
            for(int j = 0; j < size; j++)
                max = std::max(grid[j][i], max);

            max_cols.push_back(max);
        }

        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                auto max_allowed = std::min(max_rows[i], max_cols[j]);
                sum += max_allowed - grid[i][j];
            }
        }

        return sum;
    }

};