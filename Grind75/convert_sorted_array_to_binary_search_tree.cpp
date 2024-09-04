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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(0, nums.size() - 1, nums);
    }

    TreeNode* build(int left, int right, const vector<int>& nums){
        // Time: O(n), Space: O(h)
        if(left > right)
            return nullptr;

        auto middle = left + (right - left) / 2;
        auto new_node = new TreeNode(nums[middle]);

        new_node->left = build(left, middle - 1, nums);;
        new_node->right = build(middle + 1, right, nums);;

        return new_node;
    }
};