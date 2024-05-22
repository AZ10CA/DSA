#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
    // Time: O(n^2), Space: O(n)
    vector<vector<int>> result;
    std::sort(array.begin(), array.end());

    for (int i = 0; i < array.size() - 2; i++) {
        int fp = i + 1, sp = int(array.size()) - 1;

        while (fp < sp) {
            auto left_num = array[fp], right_num = array[sp];
            auto sum = left_num + right_num;

            if (sum == targetSum - array[i]) {
                result.push_back({array[i], left_num, right_num});
                fp++;
                sp--;
            } else if (sum < targetSum - array[i])
                fp++;
            else
                sp--;
        }
    }

    return result;
}
