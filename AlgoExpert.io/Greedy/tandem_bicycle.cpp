#include <vector>

using namespace std;

int tandemBicycle(vector<int> red, vector<int> blue, bool fastest) {
    // Time: O(nlogn), Space: O(1)
    std::sort(red.begin(), red.end());
    std::sort(blue.begin(), blue.end());
    if (fastest)
        std::reverse(blue.begin(), blue.end());

    int sum = 0;
    for (auto i = 0; i < blue.size(); i++)
        sum += std::max(blue[i], red[i]);
    return sum;
}
