#include <vector>

using namespace std;

int kadanesAlgorithm(vector<int> array) {
    // Time: O(n), Space: O(1)
    if (array.empty())
        return 0;

    int current_sum = array[0];
    int ans = current_sum;
    for (int i = 1; i < array.size(); i++) {
        current_sum = std::max(array[i], current_sum + array[i]);
        ans = std::max(ans, current_sum);
    }
    return ans;
}
