class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        // Time: O(n * m), Space: O(n * m)
        int mat_size = mat.size() * mat[0].size();
        if(r * c != mat_size)
            return mat;

        int idx = 0;
        vector<vector<int>> result(r, vector<int>(c, 0));
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                result[i][j] = get_next(mat, idx++);
            }
        }

        return result;
    }

    int get_next(const vector<vector<int>>& matrix, int idx){
        int row_size = matrix[0].size(), col_size = matrix.size();
        int row = idx / row_size;
        int col = idx - row * row_size;
        return matrix[row][col];
    }
};