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
    int sumOfLeftLeaves(TreeNode* root) {
        return traverse(nullptr, root);
    }

    int traverse(TreeNode* parent, TreeNode* root){
        // Time: O(n), Space: O(n)
        if(not root)
            return 0;

        auto left = traverse(root, root->left);
        auto right = traverse(root, root->right);
        auto sum = left + right;

        if(parent && parent->left == root && !root->left && !root->right)
            sum += root->val;

        return sum;
    }
};