#include <vector>
#include <unordered_set>

using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
    // Time & Space: O(n)
    unordered_set<int> required;

    for (auto num: array) {
        if (required.find(num) != required.end())
            return {num, targetSum - num};
        required.insert(targetSum - num);
    }

    return {};
}
