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
typedef unsigned long long ull;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // Time: O(n), Space: O(n)
        ull answer = 0;
        queue<pair<TreeNode*, ull>> to_visit;

        to_visit.emplace(root, 1);

        while(not to_visit.empty()){
            int level_size = to_visit.size();
            answer = std::max(answer, to_visit.back().second - to_visit.front().second + 1);

            while(level_size--){
                const auto[node, idx] = to_visit.front();
                to_visit.pop();

                if(node->left)
                    to_visit.emplace(node->left, 2 * idx);

                if(node->right)
                    to_visit.emplace(node->right, 2 * idx + 1);
            }
        }

        return answer;
    }
};