#include <vector>

using namespace std;

int minimumWaitingTime(vector<int> queries) {
    // Time: O(nlogn), Space: O(1)
    std::sort(queries.begin(), queries.end());
    int total_sum = 0, running_sum = 0;

    for (int i = 0; i < queries.size(); i++) {
        total_sum += running_sum;
        running_sum += queries[i];
    }

    return total_sum;
}
