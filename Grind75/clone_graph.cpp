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

        unordered_map<Node*, Node*> map;
        queue<Node*> to_visit;

        to_visit.push(node);
        map[node] = new Node(node->val);

        while(!to_visit.empty()){
            auto node = to_visit.front();
            to_visit.pop();

            auto clone_node = map[node];

            for(auto child: node->neighbors){
                if(map.find(child) == map.end()){
                    to_visit.push(child);
                    auto copy = new Node(child->val);
                    map[child] = copy;
                }
                clone_node->neighbors.push_back(map[child]);
            }
        }

        return map[node];
    }
};