#include <vector>
#include <algorithm>

using namespace std;

vector<int> merge_two_sorted_arrays(const vector<int> &first, const vector<int> &second);

vector<int> sortedSquaredArray(vector<int> array) {
    // Time & Space: O(n)
    vector<int> negative_nums, positive_nums;

    // find the last negative number
    for (auto each: array)
        if (each < 0)
            negative_nums.push_back(each * each);
        else
            positive_nums.push_back(each * each);


    std::reverse(negative_nums.begin(), negative_nums.end());

    auto result = merge_two_sorted_arrays(negative_nums, positive_nums);

    return result;
}

vector<int> merge_two_sorted_arrays(const vector<int> &first, const vector<int> &second) {
    int fp = 0, sp = 0;
    vector<int> sorted;

    while (fp < first.size() && sp < second.size())
        if (first[fp] < second[sp])
            sorted.push_back(first[fp++]);
        else
            sorted.push_back(second[sp++]);

    while (fp < first.size())
        sorted.push_back(first[fp++]);

    while (sp < second.size())
        sorted.push_back(second[sp++]);

    return sorted;
}
