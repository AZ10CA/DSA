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
    int rangeSumBST(TreeNode* root, int low, int high) {
        // Time: O(n), Space: O(1)
        if(not root)
            return 0;

        auto left = rangeSumBST(root->left, low, high);
        auto right = rangeSumBST(root->right, low, high);

        if(root->val < low || root->val > high)
            return left + right;
        return left + right + root->val;
    }

};