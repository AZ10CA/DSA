class Solution {
    vector<vector<int>> table;
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // Time: O(nm), Space: O(nm)
        // 'table' stores, for (i, j), the size of the maximum square that has (i, j) as its top-left corner.
        table = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), -1));
        dp(0, 0, matrix);

        int max_element = 0;
        for(int i = 0; i < table.size(); i++)
            for(int j = 0; j < table[0].size(); j++)
                max_element = std::max(max_element, table[i][j]);

        return max_element * max_element;
    }

    int dp(int i, int j, const vector<vector<char>>& matrix){
        int rows = matrix.size(), cols = matrix[0].size();
        if(i >= rows || j >= cols || i < 0 || j < 0 )
            return 0;

        if(i == rows - 1 || j == cols - 1)
            return table[i][j] = matrix[i][j] - '0';


        auto& memo = table[i][j];
        if(memo != -1)
            return memo;

        auto right = dp(i, j + 1, matrix);
        auto bottom = dp(i + 1, j, matrix);
        auto diagonal = dp(i + 1, j + 1, matrix);
        // Example: If the right neighbor forms a 2x2 square and the same applies to the other two neighbors,
        // then we can form a 3x3 square. However, if even one of the neighbors cannot do this, then we are limited.
        if(matrix[i][j] == '0')
            return memo = 0;

        return memo = 1 + std::min({right, bottom, diagonal});
    }
};