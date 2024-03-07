#include <vector>
using namespace std;

vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target) {
    // Time: O(n + m), Space: O(1)
    int row = 0, col = matrix[0].size() - 1;
    while(row < matrix.size() && col >= 0){
        if(matrix[row][col] == target){
            return {row, col};
        }
        if(target < matrix[row][col]){
            col--;
        } else {
            row++;
        }
    }

    return {-1, -1};
}
