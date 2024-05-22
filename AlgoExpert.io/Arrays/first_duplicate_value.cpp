#include <vector>

using namespace std;

int firstDuplicateValue(vector<int> array) {
    // Time: O(n), Space: O(1)
    for (int i = 0; i < array.size(); i++) {
        int current_num = array[i];
        if (array[std::abs(current_num) - 1] < 0)
            return std::abs(current_num);
        array[std::abs(current_num) - 1] *= -1;
    }
    return -1;
}
