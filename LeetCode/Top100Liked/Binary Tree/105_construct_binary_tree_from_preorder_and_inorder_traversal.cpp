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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Time & Space: O(n)
        unordered_map<int, int> inorder_map;

        for (int i = 0; i < inorder.size(); i++)
            inorder_map[inorder[i]] = i;

        int idx = 0;
        return build(idx, inorder_map, preorder, 0, inorder.size() - 1);
    }

    TreeNode *build(int &idx, unordered_map<int, int> &inorder_map, const vector<int> &preorder, int left, int right) {
        if (left > right)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[idx++]);
        root->left = build(idx, inorder_map, preorder, left, inorder_map[root->val] - 1);
        root->right = build(idx, inorder_map, preorder, inorder_map[root->val] + 1, right);

        return root;
    }
};