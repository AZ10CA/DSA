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

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return isValid(root, INT_MIN, INT_MAX);
    }

    bool isValid(TreeNode *node, long long min, long long max) {
        if (!node)
            return true;
        auto isValueValid = node->val >= min && node->val <= max;
        auto isLeftSubtreeValid = isValid(node->left, min, node->val - 1ll);
        auto isRightSubtreeValid = isValid(node->right, node->val + 1ll, max);

        return isValueValid && isLeftSubtreeValid && isRightSubtreeValid;
    }
};