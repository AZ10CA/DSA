class Solution {
public:
    typedef vector<vector<int>>  matrix;
    int matrixScore(vector<vector<int>>& grid) {
        // Time: O(nm), Space: O(1)
        // set the first to 1s
        for(int i = 0; i < grid.size(); i++)
            if(grid[i][0] == 0)
                flip_row(i, grid);

        // if less than half of the bits in the second columns are 0, flip the column
        for(int i = 0; i < grid[0].size(); i++){
            auto count = count_ones_in_col(i, grid);
            if(count < grid.size() - count)
                flip_col(i, grid);
        }

        // sum the result
        int power = grid[0].size() - 1;
        auto sum = 0;
        for(int j = 0; j < grid[0].size(); j++){
            for(int i = 0; i < grid.size(); i++)
                sum += (1 << power) * grid[i][j];

            power--;
        }

        return sum;

    }

    void flip_row(int i, matrix& grid){
        for(int j = 0; j < grid[0].size(); j++)
            grid[i][j] = !grid[i][j];
    }

    void flip_col(int i, matrix& grid){
        for(int j = 0; j < grid.size(); j++)
            grid[j][i] = !grid[j][i];
    }

    int count_ones_in_col(int col, matrix& grid){
        auto cnt = 0;
        for(int i = 0; i < grid.size(); i++)
            cnt += grid[i][col] == 1;

        return cnt;
    }
};