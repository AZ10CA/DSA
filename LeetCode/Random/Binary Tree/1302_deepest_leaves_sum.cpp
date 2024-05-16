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
    int deepestLeavesSum(TreeNode* root) {
        // Time: O(n), Space: O(n)
        queue<TreeNode*> to_visit;
        to_visit.push(root);
        auto last_level = 0;

        while(not to_visit.empty()){
            auto size = (int)to_visit.size();
            auto sum = 0;
            while(size--){
                auto node = to_visit.front();
                to_visit.pop();

                sum += node->val;
                if(node->left) to_visit.push(node->left);
                if(node->right) to_visit.push(node->right);
            }

            last_level = sum;
        }

        return last_level;
    }
};