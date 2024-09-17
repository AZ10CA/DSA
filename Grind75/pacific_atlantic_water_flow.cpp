class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        // Time: O(nm), Space: O(nm)
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> p_visited(rows, vector<int>(cols, false));
        vector<vector<int>> result;


        // Phase 1: Pacific
        vector<pair<int, int>> on_edge;
        for(int i = 0; i < cols; i++)
            on_edge.emplace_back(0, i);

        for(int i = 0; i < rows; i++)
            on_edge.emplace_back(i, 0);

        // dfs from the edge vertices and mark the reachable neighbours as visited
        vector<vector<bool>> to_pacific(rows, vector<bool>(cols, false));
        for(auto&[i, j]: on_edge)
            dfs(i, j, to_pacific, grid);

        on_edge.clear();

        // Phase 2: Atlantic
        for(int i = 0; i < cols; i++)
            on_edge.emplace_back(rows - 1, i);

        for(int i = 0; i < rows; i++)
            on_edge.emplace_back(i, cols - 1);

        vector<vector<bool>> to_atlantic(rows, vector<bool>(cols, false));
        for(auto&[i, j]: on_edge)
            dfs(i, j, to_atlantic, grid);

        // Phase 3: gather vertices that can reach both oceans
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                if(to_pacific[i][j] && to_atlantic[i][j])
                    result.push_back({i, j});

        return result;
    }

    void dfs(int i, int j, vector<vector<bool>>& visited, const vector<vector<int>>& grid){
        if(visited[i][j])
            return;

        visited[i][j] = true;

        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(auto&[x, y]: dirs){
            auto new_i = i + x;
            auto new_j = j + y;
            if(new_i < 0 || new_j < 0 || new_i >= visited.size() || new_j >= visited[0].size() || grid[new_i][new_j] < grid[i][j])
                continue;

            dfs(new_i, new_j, visited, grid);
        }
    }
};