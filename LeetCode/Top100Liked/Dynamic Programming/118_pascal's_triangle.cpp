class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // Time: O(n^2), Space: O(n^2)
        vector<vector<int>> pascal(numRows, vector<int>(numRows, 0));
        for (int i = 0; i < numRows; i++)
            pascal[i][i] = pascal[i][0] = 1;

        for (int i = 0; i < numRows; i++) {
            for (int j = 1; j < i; j++) {
                if (pascal[i][j] != 0)
                    continue;
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }

        vector<vector<int>> normalized;
        for (int i = 0; i < numRows; i++) {
            vector<int> row;
            for (int j = 0; j <= i; j++)
                row.push_back(pascal[i][j]);
            normalized.push_back(std::move(row));
        }

        return normalized;
    }
};


/**
n = 5
1, 0, 0, 0, 0
1, 1, 0, 0, 0 
1, 0, 1, 0, 0 
1, 0, 0, 1, 0
1, 0, 0, 0, 1

pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j]
*/