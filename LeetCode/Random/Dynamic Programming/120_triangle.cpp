class Solution {
    vector<vector<int>> table;
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // Time: O(mn), Space: O(mn)
        table = vector<vector<int>>(triangle.size(), vector<int>(triangle[triangle.size() - 1].size(), -1));

        return dp(0, 0, triangle);
    }

    int dp(int i, int j, const vector<vector<int>>& graph){
        if(i >= graph.size() || j >= graph[i].size())
            return INT_MAX;

        if(i == graph.size() - 1)
            return graph[i][j];

        auto& memo = table[i][j];
        if(memo != -1)
            return memo;

        auto go_left = dp(i + 1, j, graph);
        auto go_right = dp(i + 1, j + 1, graph);

        auto min_path = std::min(go_left, go_right);
        if(min_path == INT_MAX)
            return min_path;

        return memo = graph[i][j] + min_path;
    }
};

/**
2
3 4
6 5 7
4 1 8 3

start: (0, 0)
        ->
            1, 0
            1, 1

            from: (i, j)
            i + 1, j
            i + 1, j + 1
*/
