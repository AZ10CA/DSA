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
    int pathSum(TreeNode* root, int targetSum) {
        // Time: O(n^2), Space: O(n)
        if(not root)
            return 0;

        int count = 0;
        queue<TreeNode*> to_visit;
        to_visit.push(root);

        while(!to_visit.empty()){
            auto node = to_visit.front();
            to_visit.pop();
            long long sum = 0;
            preorder(node, targetSum, count, sum);

            if(node->left)
                to_visit.push(node->left);

            if(node->right)
                to_visit.push(node->right);
        }

        return count;
    }

    void preorder(TreeNode* root, int target, int& count, long long& sum){
        if(!root)
            return;

        sum += root->val;
        if(sum == target)
            count++;

        preorder(root->left, target, count, sum);
        preorder(root->right, target, count, sum);

        sum -= root->val;
    }
};