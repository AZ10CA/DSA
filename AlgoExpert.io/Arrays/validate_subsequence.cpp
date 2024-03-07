#include <vector>

using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
    // Time: O(n), Space: O(1)
    int idx = 0;

    for (int i = 0; i < array.size() && idx < sequence.size(); i++) {
        if (sequence[idx] == array[i])
            idx++;
    }

    return idx == sequence.size();
}
