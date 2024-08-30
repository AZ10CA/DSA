class Solution {
    int n, k;
    vector<vector<vector<double>>> table;
public:
    double knightProbability(int n, int k, int row, int column) {
        // Time: O(n ^ 2 * k), Space: O(n ^ 2 * k)
        this->table = vector<vector<vector<double>>>(n, vector<vector<double>>(n, vector<double>(k, -1)));
        this->k = k, this->n = n;
        return traverse(row, column, 0);
    }

    bool is_valid(int i, int j, int n){
        return i >= 0 && j >= 0 && i < n && j < n;
    }

    double traverse(int i, int j, int move_count){
        if(not is_valid(i, j, n))
            return 0;

        if(move_count == k)
            return 1;

        auto& memo = table[i][j][move_count];
        if(memo != -1)
            return memo;

        return memo = (traverse(i - 2, j - 1, move_count + 1) + traverse(i - 2, j + 1, move_count + 1) +
                       traverse(i - 1, j - 2, move_count + 1) + traverse(i - 1, j + 2, move_count + 1) +
                       traverse(i + 1, j - 2, move_count + 1) + traverse(i + 1, j + 2, move_count + 1) +
                       traverse(i + 2, j - 1, move_count + 1) + traverse(i + 2, j + 1, move_count + 1)) / 8;
    }
};