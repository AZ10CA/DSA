/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* root, TreeNode* clone, TreeNode* target) {
        // Time: O(n), Space: O(n)
        if(not root)
            return nullptr;

        if(root == target)
            return clone;

        auto left = getTargetCopy(root->left, clone->left, target);
        auto right = getTargetCopy(root->right, clone->right, target);

        if(left || right)
            return left ? left : right;

        return nullptr;
    }
};