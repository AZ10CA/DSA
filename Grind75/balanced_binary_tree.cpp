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

struct TreeInfo {
    bool is_balanced = true;
    int height = 0;

    TreeInfo(): is_balanced(true), height(0){}

    TreeInfo(const TreeInfo& left_subtree, const TreeInfo& right_subtree){
        height = std::max(left_subtree.height, right_subtree.height) + 1;
        is_balanced = left_subtree.is_balanced && right_subtree.is_balanced && std::abs(left_subtree.height - right_subtree.height) <= 1;
    }
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        auto info = postorder(root);
        return info.is_balanced;
    }

    TreeInfo postorder(TreeNode* root){
        // Time: O(n), Space: O(n)
        if(root == nullptr)
            return TreeInfo();

        auto left_info = postorder(root->left);
        auto right_info = postorder(root->right);

        return TreeInfo(left_info, right_info);
    }
};