#include <vector>

using namespace std;

int longestPeak(vector<int> array) {
    // Time: O(n), Space: O(n)
    /*
    inc -> 1, 2, 3, 1, 2, 1, 2, 1, 1, 1, 1, 2, 3
    dec -> 1, 1, 1, 1, 2, 1, 5, 4, 3, 2, 1, 1, 1
    */
    vector<int> left_to_right(array.size(), 1), right_to_left(array.size(), 1);
    for (int i = 1; i < array.size(); i++) {
        if (array[i] > array[i - 1])
            left_to_right[i] += left_to_right[i - 1];
    }

    for (int i = int(array.size()) - 2; i >= 0; i--) {
        if (array[i] > array[i + 1])
            right_to_left[i] += right_to_left[i + 1];
    }
    int max_peak = 0;

    for (int i = 1; i < int(array.size()) - 1; i++) {
        if (left_to_right[i] > left_to_right[i - 1] && right_to_left[i] > right_to_left[i + 1])
            max_peak = std::max(left_to_right[i] + right_to_left[i] - 1, max_peak);
    }

    return max_peak;
}
