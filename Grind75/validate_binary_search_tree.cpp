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
    bool isValidBST(TreeNode* root, long long min = INT_MIN, long long max = INT_MAX) {
        // Time: O(n), Space: O(h)
        if(not root)
            return true;

        auto left_subtree = isValidBST(root->left, min, root->val * 1ll - 1);
        auto right_subtree = isValidBST(root->right, root->val * 1ll + 1, max);

        return left_subtree && right_subtree && root->val >= min && root->val <= max;
    }
};