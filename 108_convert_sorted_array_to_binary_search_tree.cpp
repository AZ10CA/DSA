/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>

using namespace std;

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return build(nums, 0, nums.size() - 1);
    }

    TreeNode *build(const vector<int> &nums, int left, int right) {
        // Time & Space: O(n)
        if (left > right)
            return nullptr;
        int middle = left + (right - left) / 2;
        auto root = new TreeNode(nums[middle]);

        root->left = build(nums, left, middle - 1);
        root->right = build(nums, middle + 1, right);

        return root;
    }
};