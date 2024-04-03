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
    void inorder(TreeNode *node, int &answer, int &k) {
        // Time: O(n), Space: O(h) recursion overhead
        if (!node || k == 0)
            return;

        inorder(node->left, answer, k);
        k--;
        if (k == 0)
            answer = node->val;
        inorder(node->right, answer, k);
    }

    int kthSmallest(TreeNode *root, int &k) {
        int answer;
        inorder(root, answer, k);
        return answer;
    }
};