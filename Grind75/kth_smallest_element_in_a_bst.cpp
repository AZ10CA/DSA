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
    int answer;
    bool found = false;
public:
    int kthSmallest(TreeNode* root, int k) {
        // Time: O(n), Space: O(h)
        int idx = 0;

        traverse(root, idx, k);

        return answer;
    }

    void traverse(TreeNode* root, int& idx, int k){
        if(not root || found)
            return;

        traverse(root->left, idx, k);
        // inorder
        idx++;
        if(idx == k){
            found = true;
            answer = root->val;
            return;
        }
        traverse(root->right, idx, k);
    }
};