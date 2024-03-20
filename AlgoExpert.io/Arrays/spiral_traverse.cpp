#include <vector>

using namespace std;
#define condition result.size() != array.size() * array[0].size()


vector<int> spiralTraverse(vector<vector<int>> array) {
    // Time: O(n), Space: O(n)
    int i_max = array.size() - 1, i_min = 0, j_max = array[0].size() - 1, j_min = 0;
    vector<int> result;

    while (condition) {
        for (int j = j_min; j <= j_max; j++)
            result.push_back(array[i_min][j]);
        i_min++;


        for (int i = i_min; i <= i_max && condition; i++)
            result.push_back(array[i][j_max]);
        j_max--;


        for (int j = j_max; j >= j_min && condition; j--)
            result.push_back(array[i_max][j]);
        i_max--;

        for (int i = i_max; i >= i_min && condition; i--)
            result.push_back(array[i][j_min]);
        j_min++;
    }

    return result;
}
