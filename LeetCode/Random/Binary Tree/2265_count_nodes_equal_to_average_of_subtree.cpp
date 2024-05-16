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
    struct TreeInfo {
        int sum;
        int count;

        TreeInfo(int sum, int count): sum(sum), count(count){}
    };

    TreeInfo* traverse(TreeNode* root, int& cnt){
        // Time: O(n), Space: O(n)
        if(not root)
            return new TreeInfo(0, 0);

        auto left = traverse(root->left, cnt);
        auto right = traverse(root->right, cnt);

        auto this_sum = left->sum + right->sum + root->val;
        auto this_count = left->count + right->count + 1;

        if(this_sum / this_count == root->val){
            cnt++;
        }
        return new TreeInfo(this_sum, this_count);
    }

public:
    int averageOfSubtree(TreeNode* root) {
        int answer = 0;
        traverse(root, answer);
        return answer;
    }
};