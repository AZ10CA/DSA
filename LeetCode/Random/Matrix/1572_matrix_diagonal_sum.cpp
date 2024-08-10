class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        // Time: O(n), Space: O(1)
        int tl_i = 0, tl_j = 0;
        int tr_i = 0, tr_j = mat.size() - 1;
        int i = tl_i, j = tl_j;
        int sz = mat.size();

        auto sum = 0;

        while(is_valid(i, j, sz))
            sum += mat[i++][j++];

        i = tr_i, j = tr_j;
        while(is_valid(i, j, sz))
            sum += mat[i++][j--];

        if(mat.size() & 1)
            sum -= mat[sz / 2][sz / 2];


        return sum;
    }

    bool is_valid(int i, int j, int sz){
        return i < sz && j < sz && i >= 0 && j >= 0;
    }
};