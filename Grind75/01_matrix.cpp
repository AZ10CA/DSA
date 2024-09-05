class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // Time: O(n^2), Space: O(n^2)
        int rows = mat.size(), cols = mat[0].size();
        vector<vector<int>> result(rows, vector<int>(cols, 1e5));
        queue<pair<int, int>> to_visit;

        // start by visiting from the zero nodes
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                if(mat[i][j] == 0){
                    to_visit.emplace(i, j);
                    result[i][j] = 0;
                }

        const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        while(not to_visit.empty()){
            auto [i, j] = to_visit.front();
            to_visit.pop();

            for(auto&[x, y]: directions){
                auto new_i = i + x;
                auto new_j = j + y;
                if(!is_valid(new_i, new_j, rows, cols))
                    continue;

                if(result[new_i][new_j] > result[i][j] + 1){
                    result[new_i][new_j] = result[i][j] + 1;
                    to_visit.emplace(new_i, new_j);
                }
            }
        }

        return result;
    }

    bool is_valid(int i, int j, int rows, int cols){
        return i >= 0 && j >= 0 && i < rows && j < cols;
    }
};