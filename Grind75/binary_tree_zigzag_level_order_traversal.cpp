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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // Time: O(n), Space: O(n)
        if(not root)
            return {};
        vector<vector<int>> levels;
        queue<TreeNode*> to_visit;

        to_visit.push(root);
        while(!to_visit.empty()){
            int level_size = to_visit.size();
            vector<int> level;

            while(level_size--){
                auto top = to_visit.front();
                to_visit.pop();
                level.push_back(top->val);
                if(top->left)
                    to_visit.push(top->left);

                if(top->right)
                    to_visit.push(top->right);
            }
            levels.push_back(std::move(level));
        }

        bool reverse = false;
        for(auto& level: levels){
            if(reverse)
                std::reverse(level.begin(), level.end());
            reverse = !reverse;
        }

        return levels;
    }
};