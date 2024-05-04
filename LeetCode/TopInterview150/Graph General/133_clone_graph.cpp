/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // Time: O(V + E), Space: O(V + E)
        if(not node)
            return nullptr;
        unordered_map<Node*, Node*> old_new;
        dfs(node, old_new);
        return old_new[node];
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& old_new){
        if(old_new.find(node) != old_new.end())
            return old_new[node];

        auto& ref = old_new[node] = new Node(node->val);
        for(auto _node: node->neighbors)
            ref->neighbors.push_back(dfs(_node, old_new));

        return ref;
    }
};