class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        // Time: O(n), Space: O(n) n: number of elements in the matrix
        vector<int> result;
        vector<pair<int, int>> starting_points;

        for(int i = 0; i < mat.size() - 1; i++)
            starting_points.emplace_back(i, 0);

        for(int j = 0; j < mat[0].size(); j++)
            starting_points.emplace_back(mat.size() - 1, j);


        auto reverse = false;
        for(auto& [i, j]: starting_points){
            auto diagonal = get_diagonal(i, j, mat);
            if(reverse)
                std::reverse(diagonal.begin(), diagonal.end());

            for(auto el: diagonal)
                result.push_back(el);

            reverse = !reverse;
        }

        return result;
    }

    vector<int> get_diagonal(int i, int j, const vector<vector<int>>& matrix){
        vector<int> result;

        while(i >= 0 && j >= 0 && i < matrix.size() && j < matrix[i].size())
            result.push_back(matrix[i--][j++]);

        return result;
    }
};