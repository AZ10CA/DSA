class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // Time: O(n^2), Space: O(1)
        fill(image, sr, sc, color);
        return image;
    }

    void fill(vector<vector<int>>& image, int i, int j, int code){
        if(image[i][j] == code)
            return;
        
        auto old_color = image[i][j];
        image[i][j] = code;

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for(auto&[x, y]: directions){
            auto new_i = i + x, new_j = j + y;
            if(new_i >= 0 && new_i < image.size() && new_j >= 0 && new_j < image[i].size() && image[new_i][new_j] == old_color)
                fill(image, new_i, new_j, code);
        }
    }
};
