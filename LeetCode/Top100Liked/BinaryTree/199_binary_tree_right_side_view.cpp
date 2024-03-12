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
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        // Time & Space: O(n)
        vector<int> result;
        getVisibleChildren(root, result, 0);
        return result;
    }

    void getVisibleChildren(TreeNode *node, vector<int> &result, int depth) {
        if (!node)
            return;
        if (depth >= result.size())
            result.push_back(node->val);
        getVisibleChildren(node->right, result, depth + 1);
        getVisibleChildren(node->left, result, depth + 1);
    }
};