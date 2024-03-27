class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Time & Space: O(mn)
        queue<pair<int, int>> to_visit;
        vector<vector<bool>> visited;
        int depth = 0;
        int fresh = 0;

        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == 2)
                    to_visit.emplace(i, j);
                else if(grid[i][j] == 1)
                    fresh++;


        while(!to_visit.empty()){
            int size = to_visit.size();
            while(size--){
                auto top = to_visit.front();
                to_visit.pop();
                grid[top.first][top.second] = 2;

                vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
                for(const auto& [x, y]: directions){
                    int new_i = top.first + x;
                    int new_j = top.second + y;
                    if(is_valid(new_i, new_j, grid)){
                        to_visit.emplace(new_i, new_j);
                        grid[new_i][new_j] = 2;
                        fresh--;
                    }
                }
            }
            depth += !to_visit.empty();
        }

        return fresh == 0 ? depth : -1;
    }

    bool is_valid(int i, int j, const vector<vector<int>>& matrix){
        return i >= 0 && j >= 0 && i < matrix.size() && j < matrix[0].size() && matrix[i][j] == 1;
    }
};