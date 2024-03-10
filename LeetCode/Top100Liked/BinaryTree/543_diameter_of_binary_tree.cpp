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
    int diameterOfBinaryTree(TreeNode *root) {
        // Time: O(n), Space: O(d)
        int ans = 0;
        length(root, ans);
        return ans - 1;
    }

    int length(TreeNode *node, int &answer) {
        if (!node)
            return 0;
        auto left = length(node->left, answer);
        auto right = length(node->right, answer);
        auto len = left + right + 1;
        auto longest_branch = std::max(left, right) + 1;
        answer = std::max(answer, len);
        return longest_branch;
    }
};