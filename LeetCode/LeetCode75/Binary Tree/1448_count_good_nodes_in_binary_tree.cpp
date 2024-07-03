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
    int goodNodes(TreeNode* root) {
        if(!root)
            return 0;

        int counter = 0;
        traverse(root, root->val, counter);

        return counter;
    }

    void traverse(TreeNode* root, int max, int& counter){
        // Time: O(n), Space: O(h)
        if(!root)
            return;

        if(root->val >= max)
            counter++;

        max = std::max(max, root->val);

        traverse(root->left, max, counter);
        traverse(root->right, max, counter);
    }
};