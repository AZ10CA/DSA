#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        // Time & Space: O(n!)
        vector<int> perm;
        vector<vector<int>> result;
        unordered_set<int> used;

        generate(perm, result, nums, used);

        return result;
    }

    void generate(vector<int> &perm, vector<vector<int>> &result, const vector<int> &nums, unordered_set<int> &used) {
        if (perm.size() == nums.size()) {
            result.push_back(perm);
            return;
        }

        for (auto num: nums) {
            if (used.find(num) != used.end())
                continue;
            perm.push_back(num);
            used.insert(num);
            generate(perm, result, nums, used);
            perm.pop_back();
            used.erase(num);
        }
    }
};