#include <vector>

using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
    // Time: O(mlogm + nlogn), Space: O(1)
    /*
    -1, 2, 5, 10, 20, 28
    15, 17, 26, 134, 135
    */
    std::sort(arrayOne.begin(), arrayOne.end());
    std::sort(arrayTwo.begin(), arrayTwo.end());

    int t1, t2;
    int track_diff = INT_MAX;
    int first_ptr = 0, second_ptr = 0;

    while (first_ptr < arrayOne.size() && second_ptr < arrayTwo.size()) {
        int first_num = arrayOne[first_ptr], second_num = arrayTwo[second_ptr];
        int diff = std::abs(first_num - second_num);
        if (diff < track_diff) {
            track_diff = diff;
            t1 = first_ptr;
            t2 = second_ptr;
        }
        if (first_num > second_num)
            second_ptr++;
        else
            first_ptr++;
    }

    return {arrayOne[t1], arrayTwo[t2]};
}
