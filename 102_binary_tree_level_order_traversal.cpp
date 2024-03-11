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
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        // Time & Space: O(n)
        if (!root)
            return {};

        vector<vector<int>> result;
        queue<TreeNode *> to_visit;
        to_visit.push(root);

        while (!to_visit.empty()) {
            vector<int> level; // current level
            int size = to_visit.size();
            for (int i = 0; i < size; i++) {
                // visit node
                auto node = to_visit.front();
                level.push_back(node->val);
                to_visit.pop();

                if (node->left)
                    to_visit.push(node->left);
                if (node->right)
                    to_visit.push(node->right);
            }
            result.push_back(std::move(level));
        }

        return result;

    }
};