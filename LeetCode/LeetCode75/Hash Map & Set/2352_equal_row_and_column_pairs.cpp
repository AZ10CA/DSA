class Solution {
public:

    struct VectorHasher {
        std::size_t operator()(const std::vector<int>& vec) const {
            std::size_t seed = vec.size();
            for (int i : vec) {
                seed ^= std::hash<int>{}(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            }
            return seed;
        }
    };

    int equalPairs(vector<vector<int>>& grid) {
        // Time: O(n^2), Space: O(n^2)
        ios::sync_with_stdio(NULL);
        cin.tie(NULL);
        cout.tie(NULL);

        unordered_map<vector<int>, int, VectorHasher> rows_ft, cols_ft;
        auto cnt = 0;

        for(auto row: grid)
            rows_ft[row]++;

        for(int i = 0; i < grid.size(); i++){
            vector<int> col;
            for(int j = 0; j < grid.size(); j++)
                col.push_back(grid[j][i]);
            cols_ft[col]++;
        }

        for(auto& [row, count]: rows_ft)
            cnt += cols_ft[row] * rows_ft[row];

        return cnt;
    }
};