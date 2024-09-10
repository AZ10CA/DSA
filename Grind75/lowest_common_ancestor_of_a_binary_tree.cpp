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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Time: O(n), Space: O(h)
        if(!root)
            return nullptr;

        if(root == p || root == q)
            return root;

        auto left_subtree = lowestCommonAncestor(root->left, p, q);
        auto right_subtree = lowestCommonAncestor(root->right, p, q);

        if(left_subtree && right_subtree)
            return root;

        return left_subtree ? left_subtree : right_subtree;
    }
};