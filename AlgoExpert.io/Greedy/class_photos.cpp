#include <vector>

using namespace std;

bool isPossible(const vector<int> &first, const vector<int> &second) {
    for (int i = 0; i < first.size(); i++) {
        if (first[i] <= second[i])
            return false;
    }

    return true;
}

bool classPhotos(vector<int> first, vector<int> second) {
    // Time: O(nlogn), Space: O(1)
    std::sort(first.begin(), first.end());
    std::sort(second.begin(), second.end());

    return isPossible(first, second) || isPossible(second, first);
}


