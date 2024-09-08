enum State { VISITED, NOT_VISITED, VISITING };

class Solution {
    vector<vector<State>> states;
public:
    int numIslands(vector<vector<char>>& grid) {
        // Time: O(mn), Space: O(mn)
        int islands_cnt = 0;
        this->states = vector<vector<State>>(grid.size(), vector<State>(grid[0].size(), State::NOT_VISITED));

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1' && states[i][j] == State::NOT_VISITED){
                    islands_cnt++;
                    dfs(i, j, grid);
                }
            }
        }

        return islands_cnt;
    }


    void dfs(int vi, int vj, const vector<vector<char>>& grid){
        if(states[vi][vj] != State::NOT_VISITED || grid[vi][vj] == '0')
            return;

        states[vi][vj] = State::VISITING;

        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for(auto&[x, y]: dirs){
            int new_i = vi + x;
            int new_j = vj + y;
            if(new_i >= 0 && new_j >= 0 && new_i < grid.size() && new_j < grid[0].size())
                dfs(new_i, new_j, grid);
        }

        states[vi][vj] = State::VISITED;
    }
};