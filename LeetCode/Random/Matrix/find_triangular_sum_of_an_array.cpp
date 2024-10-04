class Solution {
public:
    int triangularSum(vector<int>& nums) {
        // Time: O(n^2), Space: O(n^2)
        int size = nums.size();
        vector<vector<int>> matrix;

        for(int i = 0; i < size; i++)
            matrix.push_back(vector<int>(size - i, 0));

        matrix[0] = nums;

        for(int i = 1; i < size; i++){
            for(int j = 0; j < size - i; j++){
                matrix[i][j] = matrix[i - 1][j] + matrix[i - 1][j + 1];
                matrix[i][j] %= 10;
            }
        }

        return matrix[size - 1][0];
    }
};