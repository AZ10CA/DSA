class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Time: O(nm), Space: O(1)
        int rows = matrix.size();
        int cols = matrix[0].size();

        bool rowZero = false, colZero = false;
        for(auto each: matrix[0])
            if(each == 0){
                rowZero = true;
                break;
            }

        for(int i = 0; i < rows; i++)
            if(matrix[i][0] == 0){
                colZero = true;
                break;
            }

        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if(rowZero)
            for(int i = 0; i < cols; i++)
                matrix[0][i] = 0;

        if(colZero)
            for(int i = 0; i < rows; i++)
                matrix[i][0] = 0;
    }
};