class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // Time: O(n^2), Space: O(1)
        int perimeter = 0;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0)
                    continue;
                for(const auto&[x, y]: directions){
                    auto new_i = i + x;
                    auto new_j = j + y;
                    if(new_i < 0 || new_i >= grid.size() || new_j < 0 || new_j >= grid[0].size())
                        perimeter++;
                    else if(grid[new_i][new_j] == 0)
                        perimeter++;
                }
            }
        }

        return perimeter;
    }
};