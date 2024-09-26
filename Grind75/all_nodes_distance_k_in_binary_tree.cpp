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
    unordered_map<int, vector<int>> graph; // adjacency list
    unordered_map<int, bool> visited;
    vector<int> result;

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Time: O(n), Space: O(n)
        // create an adjacency list from the tree
        create_graph(root);

        // run dfs from the target node and find all nodes that could be reached with exactly 'k' steps
        dfs(target->val, k);

        return result;
    }

    void dfs(int src, int k){
        if(visited[src])
            return;

        visited[src] = true;

        if(k == 0){
            result.push_back(src);
            return;
        }

        for(auto& neighbour: graph[src])
            dfs(neighbour, k - 1);
    }

    void create_graph(TreeNode* root){
        queue<TreeNode*> to_visit;
        to_visit.push(root);

        while(!to_visit.empty()){
            auto node = to_visit.front();
            to_visit.pop();
            visited[node->val] = false;

            if(node->left){
                graph[node->val].push_back(node->left->val);
                graph[node->left->val].push_back(node->val);
                to_visit.push(node->left);
            }

            if(node->right){
                graph[node->val].push_back(node->right->val);
                graph[node->right->val].push_back(node->val);
                to_visit.push(node->right);
            }
        }
    }
};