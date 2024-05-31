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
    vector<int> postorderTraversal(TreeNode* root) {
        // Time: O(n), Space: O(n)
        vector<int> result;
        traverse(root, result);

        return result;
    }

    void traverse(TreeNode* root, vector<int>& result){
        if(not root)
            return;

        traverse(root->left, result);
        traverse(root->right, result);
        result.push_back(root->val);
    }
};