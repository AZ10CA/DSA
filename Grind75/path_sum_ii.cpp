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
    int sum = 0;
    vector<int> path;
    vector<vector<int>> result;

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        // Time: O(n), Space: O(n)
        traverse(root, targetSum);

        return result;
    }

    void traverse(TreeNode* root, int target){
        if(not root)
            return;

        path.push_back(root->val);
        sum += root->val;

        traverse(root->left, target);
        traverse(root->right, target);

        bool is_leaf = !root->left && !root->right;
        if(is_leaf && sum == target)
            result.push_back(path);

        path.pop_back();
        sum -= root->val;
    }
};