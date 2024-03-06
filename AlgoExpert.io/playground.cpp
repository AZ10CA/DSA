#include <vector>
#include <stack>
#include <iostream>

std::vector<int> findNextGreaterElement(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> nge(n, -1);
    std::stack<int> s;

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && nums[i] > s.top()) {
            nge[s.size() - 1] = nums[i];
            s.pop();
        }
        s.push(nums[i]);
    }
    return nge;
}

int main() {
    std::vector<int> nums = {2, 7, 3, 5, 4, 6, 8, 1};
    std::vector<int> result = findNextGreaterElement(nums);

    std::cout << "Next greater elements: ";
    for (int n : result) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
