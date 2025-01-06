class Solution {
public:
    string convert(string s, int numRows) {
        // Time: O(n), Space: O(n)
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        if(numRows == 1)
            return s;

        vector<vector<char>> zigzag_matrix(numRows, vector<char>(1000, ' '));
        pair<int, int> matrix_idx = make_pair(0, 0);
        bool go_zigzag = false;

        for(auto letter: s){
            zigzag_matrix[matrix_idx.first][matrix_idx.second] = letter;
            int rows = numRows;
            int cols = zigzag_matrix[0].size();
            if(not go_zigzag){
                if(matrix_idx.first == rows - 1){
                    go_zigzag = true;
                    matrix_idx.first --;
                    matrix_idx.second++;
                } else {
                    matrix_idx.first++;
                }
            } else {
                if(matrix_idx.first == 0){
                    go_zigzag = false;
                    matrix_idx.first++;
                } else {
                    matrix_idx.first--;
                    matrix_idx.second++;
                }
            }
        }

        string result;
        for(auto row: zigzag_matrix)
            result += gather(row);

        return result;
    }

    string gather(const vector<char>& row){
        string result;
        for(auto each: row)
            if(each != ' ')
                result.push_back(each);

        return result;
    }
};