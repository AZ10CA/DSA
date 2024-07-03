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

struct TreeInfo {
    bool isBalanced;
    int height = 0;

    TreeInfo(int height, bool isBalanced = true): height(height), isBalanced(isBalanced) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        // Time: O(n), Space: O(n)
        auto info = traverse(root);
        return info.isBalanced;
    }

    TreeInfo traverse(TreeNode* root){
        if(not root)
            return TreeInfo(0, true);

        auto left_subtree = traverse(root->left);
        auto right_subtree = traverse(root->right);

        if(left_subtree.isBalanced && right_subtree.isBalanced && std::abs(left_subtree.height - right_subtree.height) <= 1)
            return TreeInfo(std::max(left_subtree.height, right_subtree.height) + 1, true);

        return TreeInfo(0, false);
    }
};