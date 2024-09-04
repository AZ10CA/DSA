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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // Time: O(mn), Space: O(m)
        if(not root)
            return subRoot == nullptr;

        if(isSameTree(root, subRoot))
            return true;

        auto left = isSubtree(root->left, subRoot);
        auto right = isSubtree(root->right, subRoot);

        return left || right;
    }

    bool isSameTree(TreeNode* first, TreeNode* second){
        if(!first && !second)
            return true;

        if(!first || !second)
            return false;

        return first->val == second->val && isSameTree(first->left, second->left) && isSameTree(first->right, second->right);
    }
};