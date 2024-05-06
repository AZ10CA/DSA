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
    TreeNode* prev;
    int answer = INT_MAX;
public:
    int getMinimumDifference(TreeNode* root) {
        // Time: O(n), Space: O(h)
        inorder(root);
        return answer;
    }

    void inorder(TreeNode* root){
        if(not root)
            return;

        inorder(root->left);
        if(prev){
            answer = std::min(std::abs(prev->val - root->val), answer);
            prev = root;
        }

        prev = root;
        inorder(root->right);
    }
};