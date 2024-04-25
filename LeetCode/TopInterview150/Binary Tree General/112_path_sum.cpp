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
    void traverse(TreeNode* node, bool& answer, int& running_sum, int target){
        // Time: O(n), Space: O(d)
        if(!node)
            return;

        running_sum += node->val;
        if(running_sum == target && !node->left && !node->right)
            answer = true;
        traverse(node->left, answer, running_sum, target);
        traverse(node->right, answer, running_sum, target);
        running_sum -= node->val;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        bool answer = false;
        int sum = 0;
        traverse(root, answer, sum, targetSum);

        return answer;
    }
};