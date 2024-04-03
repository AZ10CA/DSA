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
    bool isSymmetric(TreeNode *root) {
        return isSame(root->left, root->right);
    }

    bool isSame(TreeNode *first, TreeNode *second) {
        // Time: O(n), Space: O(h)
        if (!first && !second)
            return true;
        if (!first || !second)
            return false;
        return first->val == second->val && isSame(first->right, second->left) && isSame(first->left, second->right);
    }
};