class NumMatrix {
    vector<vector<int>> table;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        // Time: O(mn), Space: O(mn)
        int rows = matrix.size(), cols = matrix[0].size();
        table = vector<vector<int>>(rows, vector<int>(cols, 0));
        for(int r = 0; r < rows; r++){
            int current_row_sum = 0;
            for(int c = 0; c < cols; c++){
                current_row_sum += matrix[r][c];
                table[r][c] = current_row_sum + (r == 0 ? 0 : table[r - 1][c]);
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int diagonal_area = dp(row1 - 1, col1 - 1);
        int top_area = dp(row1 - 1, col2);
        int left_area = dp(row2, col1 - 1);

        auto erased_area = top_area + left_area - diagonal_area;
        int total_area = dp(row2, col2);
        return total_area - erased_area;
    }

    int dp(int row, int col){
        if(row < 0 || col < 0)
            return 0;

        return table[row][col];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */