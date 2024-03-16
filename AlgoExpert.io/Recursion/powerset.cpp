#include <vector>

using namespace std;

void generate_subsets(const vector<int> &numbers, int idx, vector<int> &curr_subset, vector<vector<int>> &result) {
    // Time & Space: O(2^n * n)
    if (idx == numbers.size()) {
        result.push_back(curr_subset);
        return;
    }

    curr_subset.push_back(numbers[idx]);
    generate_subsets(numbers, idx + 1, curr_subset, result);
    curr_subset.pop_back();
    generate_subsets(numbers, idx + 1, curr_subset, result);
}

vector<vector<int>> powerset(vector<int> array) {
    vector<vector<int>> result;
    vector<int> subset;

    generate_subsets(array, 0, subset, result);

    return result;
}
