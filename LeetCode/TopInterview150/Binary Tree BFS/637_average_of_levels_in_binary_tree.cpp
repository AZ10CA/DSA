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
    vector<double> averageOfLevels(TreeNode* root) {
        // Time: O(n), Space: O(n)
        queue<TreeNode*> to_visit;
        vector<double> result;
        to_visit.push(root);

        while(to_visit.size()){
            auto size = to_visit.size();
            double sum = 0;
            for(int i = 0; i < size; i++){
                auto node = to_visit.front();
                to_visit.pop();
                sum += node->val;

                if(node->left)
                    to_visit.push(node->left);

                if(node->right)
                    to_visit.push(node->right);
            }
            result.push_back(sum / size);
        }

        return result;
    }
};