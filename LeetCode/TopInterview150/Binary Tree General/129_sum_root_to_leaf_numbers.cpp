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
    int sumNumbers(TreeNode* root) {
        // Time: O(n), Space: O(n)
        vector<int> nums;
        int current;

        traverse(root, current, nums);
        auto sum = 0;

        for(auto num: nums)
            sum += num;

        return sum;
    }

    void traverse(TreeNode* root, int& current_num, vector<int>& integers){
        if(not root)
            return;
        current_num = current_num * 10 + root->val;
        if(!root->left && !root->right)
            integers.push_back(current_num);
        traverse(root->left, current_num, integers);
        traverse(root->right, current_num, integers);
        current_num /= 10;
    }
};