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
    vector<int> preorder, inorder;
    unordered_map<int, int> num_to_inorder_idx;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Time: O(n), Space: O(n)
        this->preorder = preorder;
        this->inorder = inorder;

        for(int i = 0; i < inorder.size(); i++)
            num_to_inorder_idx[inorder[i]] = i;

        int idx = 0;
        return build(0, inorder.size() - 1, idx);
    }

    TreeNode* build(int left_idx, int right_idx, int& root_idx){
        if(left_idx > right_idx)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[root_idx]);

        root_idx++;
        root->left = build(left_idx, num_to_inorder_idx[root->val] - 1, root_idx);
        root->right = build(num_to_inorder_idx[root->val] + 1, right_idx, root_idx);

        return root;
    }
};