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
        // Time: O(n * m), Space: O(n)
        if(not subRoot)
            return true;
        if(not root)
            return false;

        if(isSame(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }

    bool isSame(TreeNode* first, TreeNode* second){
        if(not first and not second)
            return true;
        if(not first or not second)
            return false;

        if(first->val != second->val)
            return false;

        return isSame(first->left, second->left) and isSame(first->right, second->right);
    }
};