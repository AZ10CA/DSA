class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Time: O(mn), Space: O(mn)
        int mn_x = 0, mx_x = matrix[0].size() - 1;
        int mn_y = 0, mx_y = matrix.size() - 1;

        vector<int> result;
#define SIZE_CONDITION result.size() != matrix.size() * matrix[0].size()
        while(SIZE_CONDITION){
            for(int i = mn_x; i <= mx_x && SIZE_CONDITION; i++){
                result.push_back(matrix[mn_y][i]);
            }
            mn_y++;

            for(int i = mn_y; i <= mx_y && SIZE_CONDITION; i++){
                cout << matrix[i][mx_x] << endl;
                result.push_back(matrix[i][mx_x]);
            }

            mx_x--;

            for(int i = mx_x; i >= mn_x && SIZE_CONDITION; i--)
                result.push_back(matrix[mx_y][i]);

            mx_y--;

            for(int i = mx_y; i >= mn_y && SIZE_CONDITION; i--)
                result.push_back(matrix[i][mn_x]);

            mn_x++;
        }

        return result;
    }
};