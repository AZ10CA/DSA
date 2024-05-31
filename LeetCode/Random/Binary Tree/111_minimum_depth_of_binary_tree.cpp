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
    int minDepth(TreeNode* root) {
        // Time: O(n), Space: O(n)
        if(not root)
            return 0;

        int answer = INT_MAX;
        traverse(root, answer, 1);

        return answer;
    }

    void traverse(TreeNode* root, int& answer, int depth){
        if(not root)
            return;

        traverse(root->left, answer, depth + 1);
        traverse(root->right, answer, depth + 1);

        if(!root->left && !root->right)
            answer = std::min(depth, answer);
    }
};