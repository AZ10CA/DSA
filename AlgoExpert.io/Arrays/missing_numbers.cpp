#include <vector>

using namespace std;

vector<int> missingNumbers(vector<int> nums) {
    // Time: O(n), Space: O(1)
    nums.push_back(1);
    nums.push_back(1);
    for (int i = 0; i < nums.size() - 2; i++) {
        auto idx = std::abs(nums[i]) - 1;
        nums[idx] *= -1;
    }

    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0)
            result.push_back(i + 1);
    }
    return result;
}
