class Solution {
public:
    vector<int> getRow(int n) {
        // Time: O(n^2), Space: O(n^2)
        vector<vector<int>> matrix(n + 1, vector<int>(n + 1, 0));

        // set elementst that are equal to one
        int last_element = 0;
        for(int i = 0; i < matrix.size(); i++)
            matrix[i][0] = matrix[i][last_element++] = 1;

        for(int i = 2; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size() - 1; j++){
                matrix[i][j] = matrix[i - 1][j - 1] + matrix[i - 1][j];
            }
        }

        return matrix[n];
    }
};