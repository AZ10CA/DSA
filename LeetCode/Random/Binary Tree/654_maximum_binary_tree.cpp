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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // Time: O(n), Space: O(n)
        return build(0, nums.size() - 1, nums);
    }

    TreeNode* build(int start, int end, vector<int>& nums){
        if(start > end)
            return nullptr;

        auto mx_ptr = std::max_element(nums.begin() + start, nums.begin() + end + 1);
        auto mx_idx = std::distance(nums.begin(), mx_ptr);
        auto new_node = new TreeNode(*mx_ptr);
        new_node->left = build(start, mx_idx - 1, nums);
        new_node->right = build(mx_idx + 1, end, nums);

        return new_node;
    }
};