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
    int sumEvenGrandparent(TreeNode* root) {
        // Time: O(n), Space: O(h)
        if(not root)
            return 0;

        auto left = sumEvenGrandparent(root->left);
        auto right = sumEvenGrandparent(root->right);

        if(root->val % 2 == 0)
            return sum_grand_children(root, 0) + left + right;

        return left + right;
    }

    int sum_grand_children(TreeNode* root, int depth){
        if(not root)
            return 0;
        if(depth != 2)
            return sum_grand_children(root->left, depth + 1) + sum_grand_children(root->right, depth + 1);
        return root->val;
    }
};