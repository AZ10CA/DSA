#include <vector>

using namespace std;

int binarySearch(vector<int> array, int target) {
    // Time: O(logn), Space: O(1)
    while (left <= right) {
        auto middle = left + (right - left) / 2;
        if (target == array[middle])
            return middle;
        if (target > array[middle])
            left = middle + 1;
        else
            right = middle - 1;
    }
    return -1;
}
