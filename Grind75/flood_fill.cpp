class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // fill_dfs(sr, sc, color, image);
        fill_bfs(sr, sc, color, image);
        return image;
    }

    void fill_dfs(int i, int j, int color, vector<vector<int>>& image){
        // DFS
        // Time: O(mn), Space: O(mn)
        if(image[i][j] == color)
            return;

        auto initial_color = image[i][j];

        image[i][j] = color;
        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, - 1}};
        for(auto&[x, y]: dirs){
            auto new_i = i + x;
            auto new_j = j + y;
            if(new_i >= 0 && new_j >= 0 && new_i < image.size() && new_j < image[i].size() && image[new_i][new_j] == initial_color)
                fill_dfs(new_i, new_j, color, image);
        }
    }

    void fill_bfs(int i, int j, int color, vector<vector<int>>& image){
        // BFS
        // Time: O(mn), Space: O(mn)
        queue<pair<int, int>> to_visit;
        to_visit.emplace(i, j);

        while(not to_visit.empty()){
            auto top = to_visit.front();
            to_visit.pop();
            auto& pixel = image[top.first][top.second];

            if(pixel == color)
                continue;

            auto initial_color = image[top.first][top.second];
            pixel = color;

            vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
            for(auto&[x, y]: dirs){
                auto new_i = top.first + x;
                auto new_j = top.second + y;
                if(new_i >= 0 && new_j >= 0 && new_i < image.size() && new_j < image[i].size() && image[new_i][new_j] == initial_color)
                    to_visit.emplace(new_i, new_j);
            }
        }
    }
};