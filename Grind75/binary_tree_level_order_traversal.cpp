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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Time: O(n), Space: O(n)
        if(not root)
            return {};
        vector<vector<int>> result;
        queue<TreeNode*> to_visit;

        to_visit.push(root);
        while(!to_visit.empty()){
            int size = to_visit.size();
            vector<int> level;
            while(size--){
                auto top = to_visit.front();
                to_visit.pop();
                level.push_back(top->val);

                if(top->left)
                    to_visit.push(top->left);

                if(top->right)
                    to_visit.push(top->right);
            }

            result.push_back(std::move(level));
        }
        return result;
    }
};