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
    void flatten(TreeNode* root) {
        // Time: O(n), Space: O(1)
        if(not root)
            return;

        flatten(root->left);
        flatten(root->right);

        auto right_subtree = root->right;
        root->right = root->left;
        root->left = nullptr;
        // now connect the last child of left subtree to the first child of right subtree
        auto ptr = root; // left subtree that was just put in the right subtree
        while(ptr->right)
            ptr = ptr->right;

        ptr->right = right_subtree;
    }
};