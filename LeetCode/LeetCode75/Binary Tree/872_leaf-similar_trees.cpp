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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        get_leaves(root1, leaves1);
        get_leaves(root2, leaves2);

        return leaves1 == leaves2;
    }

    void get_leaves(TreeNode* root, vector<int>& result){
        // Time: O(n), Space: O(h)
        if(!root)
            return;

        if(!root->left && !root->right)
            result.push_back(root->val);

        get_leaves(root->left, result);
        get_leaves(root->right, result);
    }
};