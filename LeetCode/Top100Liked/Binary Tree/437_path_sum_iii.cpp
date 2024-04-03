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
    int answers = 0;
public:
    int pathSum(TreeNode* root, long long targetSum) {
        // Time: O(n^2), Space: O(n)
        // NOTE: There is an O(n) solution with unordered_map
        if(!root)
            return 0;
        traverse(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        return answers;
    }


    void traverse(TreeNode* root, long long sum){
        if(!root)
            return;

        if(root->val == sum)
            answers++;

        traverse(root->left, sum - root->val);
        traverse(root->right, sum - root->val);
    }

};