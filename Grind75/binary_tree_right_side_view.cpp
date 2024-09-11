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
    unordered_map<int, int> right_side;
public:
    vector<int> rightSideView(TreeNode* root) {
        // Time: O(n), Space: O(h)
        traverse(root, 0);

        int size = right_side.size();
        vector<int> result(size);

        for(int i = 0; i < size; i++)
            result[i] = right_side[i];

        return result;
    }

    void traverse(TreeNode* root, int depth){
        if(not root)
            return;

        if(right_side.find(depth) == right_side.end())
            right_side[depth] = root->val;

        traverse(root->right, depth + 1);
        traverse(root->left, depth + 1);
    }
};