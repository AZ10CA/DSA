/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // return make_path(root, p, q);
        return lca(root, p, q);
    }

    /** Solution 1 */
    TreeNode* make_path(TreeNode* root, TreeNode* p, TreeNode* q){
        // Time: O(n), Space: O(n) -> O(logn) time and space when balanced
        vector<TreeNode*> path_to_p, path_to_q;
        construct(root, p, path_to_p);
        construct(root, q, path_to_q);

        auto answer = root;
        for(int i = 0; i < std::min(path_to_p.size(), path_to_q.size()); i++){
            if(path_to_p[i] == path_to_q[i])
                answer = path_to_p[i];
        }

        return answer;
    }

    void construct(TreeNode* root, TreeNode* node, vector<TreeNode*>& path){
        if(not root)
            return;

        path.push_back(root);
        if(root->val == node->val)
            return;

        if(root->val > node->val)
            construct(root->left, node, path);
        else
            construct(root->right, node, path);
    }

    /** Solution 2 */
    TreeNode* lca(TreeNode* root, TreeNode* first, TreeNode* second){
        // Time: O(n), Space: O(n)
        if(not root)
            return nullptr;

        if(root->val > first->val && root->val > second->val)
            return lca(root->left, first, second);

        if(root->val < first->val && root->val < second->val)
            return lca(root->right, first, second);

        return root;
    }
};