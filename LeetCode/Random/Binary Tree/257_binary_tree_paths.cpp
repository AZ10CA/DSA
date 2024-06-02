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
    vector<string> binaryTreePaths(TreeNode* root) {
        // Time: O(n), Space: O(n)
        vector<string> result;
        vector<int> path;

        traverse(root, result, path);

        return result;
    }

    void traverse(TreeNode* root, vector<string>& result, vector<int>& current_path){
        if(not root)
            return;
        current_path.push_back(root->val);

        if(not root->left and not root->right)
            result.push_back(make_path(current_path));

        traverse(root->left, result, current_path);
        traverse(root->right, result, current_path);

        current_path.pop_back();
    }

    string make_path(const vector<int>& path){
        string result;
        for(int i = 0; i < path.size(); i++){
            auto num = path[i];
            if(i != 0)
                result += "->";
            result += to_string(num);
        }

        return result;
    }
};