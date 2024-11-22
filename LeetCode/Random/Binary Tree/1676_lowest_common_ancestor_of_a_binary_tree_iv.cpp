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
    unordered_set<TreeNode*> wanted;
    TreeNode* answer = nullptr;
    int max_found = 0;

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        // Time: O(n), Space: O(n)
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);


        wanted = unordered_set<TreeNode*>(nodes.begin(), nodes.end());
        traverse(root);

        return answer;
    }

    int traverse(TreeNode* root){
        if(not root)
            return 0;

        auto left_info = traverse(root->left);
        auto right_info = traverse(root->right);

        auto nodes_found = left_info + right_info + (wanted.find(root) != wanted.end());
        if(nodes_found > max_found){
            answer = root;
            max_found = nodes_found;
        }

        return nodes_found;
    }
};