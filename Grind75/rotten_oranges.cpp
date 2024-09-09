class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Time: O(mn), Space: O(mn)
        int level = -1;
        queue<pair<int, int>> to_visit;
        const vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[i].size(); j++)
                if(grid[i][j] == 2)
                    to_visit.emplace(i, j);

        while(!to_visit.empty()){
            int size = to_visit.size();
            while(size--){
                auto top = to_visit.front();
                int i = top.first, j = top.second;
                to_visit.pop();

                for(auto&[x, y]: dirs){
                    auto new_i = i + x;
                    auto new_j = j + y;
                    if(new_i >= 0 && new_j >= 0 && new_i < grid.size() && new_j < grid[0].size() && grid[new_i][new_j] == 1){
                        grid[new_i][new_j] = 2;
                        to_visit.emplace(new_i, new_j);
                    }
                }
            }

            level++;
        }

        for(auto& row: grid)
            for(auto& cell: row)
                if(cell == 1)
                    return -1;

        return level == -1 ? 0 : level;
    }
};