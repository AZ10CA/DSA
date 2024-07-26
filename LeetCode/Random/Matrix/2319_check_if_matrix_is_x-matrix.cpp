class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        // Time: O(n^2), Space: O(1)
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid.size(); j++){
                if(i + j == grid.size() - 1 || i == j){
                    if(grid[i][j] == 0)
                        return false;
                } else if(grid[i][j] != 0)
                    return false;
            }
        }

        return true;
    }
};