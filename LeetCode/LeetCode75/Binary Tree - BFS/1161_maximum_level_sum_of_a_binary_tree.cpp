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
    int maxLevelSum(TreeNode* root) {
        // Time: O(n), Space: O(n)
        queue<TreeNode*> to_visit;
        to_visit.push(root);
        long long max_level_sum = root->val;
        int current_level = 1;
        int max_level = current_level;

        while(!to_visit.empty()){
            int size = to_visit.size();
            long long level_sum = 0;
            while(size--){
                auto top = to_visit.front();
                to_visit.pop();
                level_sum += top->val;
                if(top->left)
                    to_visit.push(top->left);
                if(top->right)
                    to_visit.push(top->right);
            }

            if(level_sum > max_level_sum){
                max_level_sum = level_sum;
                max_level = current_level;
            }
            current_level++;
        }

        return max_level;
    }
};